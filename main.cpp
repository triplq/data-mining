#include <iostream>

class DataMining{
protected:
    std::string data;
    std::string file;

    void openFile() const{
        std::cout << "Openning. . .\n";
    };
    void extractFile() const{
        std::cout << "Extracting. . .\n";
    }    
    virtual void parseFile() = 0;
    void analyzeData() const{
        std::cout << "Analyzing data. . .\n";
    }    
    void sendReport() const{
        std::cout << "Sending report. . .\n";
    }

public:
    DataMining(std::string ffile) : file{ffile} {};
    void doWork(){
        this->openFile();
        this->extractFile();
        this->parseFile();
        this->analyzeData();
        this->sendReport();
    };
};

class PDFDataMining : public DataMining{
public:
    using DataMining::DataMining;

    void parseFile() override{
        std::cout << "Parsing PDF. . .\n";
        this->data = this->file;
    }
};

class CSVDataMining : public DataMining{
public:
    using DataMining::DataMining;

    void parseFile() override{
        std::cout << "Parsing CSV. . .\n";
        this->data = this->file;
    }
};

class DOCDataMining : public DataMining{
public:
    using DataMining::DataMining;

    void parseFile() override{
        std::cout << "Parsing DOC. . .\n";
        this->data = this->file;
    }
};

int main(){
    std::string some_file{"something in a file"};
    
    PDFDataMining PDF(some_file);
    PDF.doWork();

    CSVDataMining CSV(some_file);
    CSV.doWork();

    DOCDataMining DOC(some_file);
    DOC.doWork();

    return 0;
};