#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Document {
    vector<string> data;
    string renderer;
    public:
    void addText(const string& text) {
        data.push_back(text);
    }

    void addImage(const string& imagePath) {
        data.push_back(imagePath );
    }
    string render() {
        if(renderer.empty()) {
            for(auto& line : data) {
                if(line.size()>4 && line.substr(line.size()-4) == ".png") {
                    renderer += "[Image path = " + line + "]\n";
                } else {
                    renderer +=line + "\n";
                }
            }
        }
        return renderer;
    }

    void saveToFile(){
        ofstream outFile("document.txt");
        if (outFile.is_open()) {
            outFile << render();
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Unable to open file";
        }
    }
};

int main() {
    Document doc;
    doc.addText("Hello, this is a sample document.");
    doc.addImage("image1.png");
    doc.addText("This document contains text and images.");
    doc.addImage("image2.png");

    cout << "Rendering Document:" << endl;
    cout << doc.render() << endl;

    doc.saveToFile();

    return 0;
}