#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentElement{
public:
    virtual string render() = 0;
    virtual ~DocumentElement() = default;
};

class TextElement : public DocumentElement{
    string s;
public:
    TextElement(const string& str) : s(str) {}
    string render() override {
        return s + "\n";
    }
};
class ImageElement : public DocumentElement{
    string s;
public:
    ImageElement(const string& str) : s(str) {}
    string render() override {
        return "[Image path = " + s + "]\n";
    }

};

class Document {
    vector<DocumentElement*> elements;
public:
    void addElement(DocumentElement& s) {
        elements.push_back(&s);
    }
    string render() const {
        string renderer;
        if(renderer.empty()) {
            for(size_t i = 0; i < elements.size(); ++i) {
                renderer += elements[i]->render();
            }
        }
        return renderer;
    }
};

class persist{
    public:
    virtual void save(const Document& doc) = 0;
};

class FilePersist :public persist{
public:
    void save (const Document& doc) override{
        ofstream outFile("document.txt");
        if (outFile.is_open()) {
            outFile << doc.render();
            outFile.close();
            cout << "Document saved" <<endl;
        } else {
            cout << "Unable to open file";
        }
    }

};
class DbPersist : public persist{
public:
    void save(const Document& doc) override{
        cout << "Text Persisted in DB:" << endl;
        // cout << doc.render() << endl;
    }
};

class DocumentEditor{
    Document& doc;
    persist& p;
public:
    DocumentEditor(Document& document, persist& pers) : doc(document), p(pers) {}
    void saveDocument(){
        p.save(doc);
    }
    void addImage(ImageElement& element){
        doc.addElement(element);
    }
    void addText(TextElement& element){
        doc.addElement(element);
    }
    void renderDocument(){
        cout << doc.render() << endl;
    }
};

int main(){
    Document doc;
    FilePersist filePers;
    DbPersist dbPers;

    DocumentEditor editor(doc, filePers);

    TextElement text1("Hello, this is a sample document.");
    ImageElement image1("image1.png");
    TextElement text2("This document contains text and images.");
    ImageElement image2("image2.png");

    editor.addText(text1);
    editor.addImage(image1);
    editor.addText(text2);
    editor.addImage(image2);

    cout << "Rendering Document:" << endl;
    editor.renderDocument();

    editor.saveDocument();

    // DocumentEditor dbEditor(doc, dbPers);
    // dbEditor.saveDocument();

    return 0;
}