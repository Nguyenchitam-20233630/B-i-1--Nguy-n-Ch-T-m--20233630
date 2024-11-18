#include <iostream>
#include <string>
using namespace std;

struct File {
    string name;       
    float size;    
    string time;       
    File* next;        
};

struct FileList {
    File* head;        
    FileList() : head(NULL) {}

    void addFile(const string& name, float size, const string& time) {
        File* newFile = new File{name, size, time, NULL};
        
        if (!head || time < head->time) { 
            newFile->next = head;
            head = newFile;
        } else {
            File* current = head;
            while (current->next && current->next->time < time) {
                current = current->next;
            }
            newFile->next = current->next;
            current->next = newFile;
        }
    }
    
 
    float calculateKich_thuoc_file() const {
        float Kich_thuoc_file = 0;
        File* current = head;
        while (current) {
            Kich_thuoc_file += current->size;
            current = current->next;
        }
        return Kich_thuoc_file;
    }
    
 
    void removeSmallestFile() {
        if (!head) return; 
        
        File *prev = NULL, *smallestPrev = NULL;
        File *current = head, *smallest = head;
        
    
        while (current) {
            if (current->size < smallest->size) {
                smallest = current;
                smallestPrev = prev;
            }
            prev = current;
            current = current->next;
        }
        if (smallestPrev) {
            smallestPrev->next = smallest->next;
        } else {
            head = head->next;
        }
        delete smallest;
    }


    void backupToUSB() {
        const float USB_CAPACITY = 32LL * 1024 * 1024 * 1024;
        while (calculateKich_thuoc_file() > USB_CAPACITY) {
            removeSmallestFile();
        }
    }

 
    void displayFiles() const {
        File* current = head;
        while (current) {
            cout << "File: " << current->name << ", Size: " << current->size << " bytes, time: " << current->time << endl;
            current = current->next;
        }
    }
};
