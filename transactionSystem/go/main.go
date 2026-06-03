// Problem Title: Concurrent Transaction Processor with Pending Queue
// Problem Description
// You are building the core transaction engine for a payment processing system. The system must process transfers between users concurrently. However, standard locking mechanisms (sync.Mutex, sync.RWMutex) are strictly forbidden. You must use Go's concurrency primitives (channels and goroutines) to ensure thread safety.

// Additionally, the system must support a "Wait for Funds" feature. If a user attempts to send money but has insufficient funds, the transaction should not fail immediately. Instead, it must be queued. If a subsequent transaction deposits enough money into that user's account, their pending transaction(s) must automatically trigger and process.

package main

import (
	"fmt"
	"sync"
)

type Transaction struct {
	SenderID   int
	ReceiverID int
	Amount     int
}

func processTransaction() (chan Transaction, chan bool, *sync.WaitGroup) {
	txChan := make(chan Transaction)
	doneChan := make(chan bool)
	wg := &sync.WaitGroup{}
	wg.Add(1)
	go func() {
		defer wg.Done()
		balances := make(map[int]int)
		balances[1] = 100
		balances[2] = 50
		balances[3] = 0

		pending := make(map[int][]Transaction)
		var resolvePending func(userID int)
		resolvePending = func(userID int) {
			if len(pending[userID]) == 0 {
				return
			}

			var stillPending []Transaction
			for _, tx := range pending[userID] {
				if balances[tx.SenderID] >= tx.Amount {
					balances[tx.SenderID] -= tx.Amount
					balances[tx.ReceiverID] += tx.Amount
					fmt.Printf("  [PENDING RESOLVED] User %d -> User %d ($%d)\n", tx.SenderID, tx.ReceiverID, tx.Amount)
					resolvePending(tx.ReceiverID)
				} else {
					stillPending = append(stillPending, tx)
				}
			}
			pending[userID] = stillPending
		}

		// The main event loop listening to the channels
		for {
			select {
			case tx := <-txChan:
				if balances[tx.SenderID] >= tx.Amount {
					balances[tx.SenderID] -= tx.Amount
					balances[tx.ReceiverID] += tx.Amount
					fmt.Printf("[PROCESSED] User %d -> User %d ($%d)\n", tx.SenderID, tx.ReceiverID, tx.Amount)
					resolvePending(tx.ReceiverID)
				} else {
					// Insufficient funds: Queue the transaction
					fmt.Printf("[QUEUED] User %d -> User %d ($%d) - Insufficient funds (Balance: $%d)\n",
						tx.SenderID, tx.ReceiverID, tx.Amount, balances[tx.SenderID])
					pending[tx.SenderID] = append(pending[tx.SenderID], tx)
				}

			case <-doneChan:
				fmt.Println("\n--- Processing Finished ---")
				fmt.Println("Final Balances:", balances)
				fmt.Println("Unprocessed Pending Transactions:", pending)
				return
			}
		}
	}()

	return txChan, doneChan, wg
}

func main() {
	txChan, doneChan, wg := processTransaction()
	fmt.Println("Initial State: User 1: $100 | User 2: $50 | User 3: $0\n")
	txChan <- Transaction{SenderID: 3, ReceiverID: 1, Amount: 40}
	txChan <- Transaction{SenderID: 2, ReceiverID: 3, Amount: 60}
	txChan <- Transaction{SenderID: 1, ReceiverID: 2, Amount: 20}
	doneChan <- true

	// Wait for the goroutine to finish its operations and exit
	wg.Wait()
}
