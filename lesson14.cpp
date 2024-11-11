#include <iostream>
#include <filesystem>
#include <fstream>
using namespace std;
namespace fisy = filesystem;
int main()
{
    fisy::path fpath = "data_folder";
    if (!fisy::exists(fpath)) {
        fisy::create_directory(fpath);
        cout << "Folder " << fpath << " create" << endl;
    }
    else { cout << "Folder already yet\n"; }
    fisy::path filep = fpath / "data.txt";
    std::ofstream file(filep);
    if (file) {
        file << "My cat is hungry" << endl;
        cout << "File" << filep << "create" << endl;
        file.close();
    }
    else { cout << "File already yet\n"; }
    if (fisy::exists(fpath)) {
        cout << "Soderzhimoe folder" << endl;
        for (auto f : fisy::directory_iterator(fpath)) {
            cout << ":" << f.path().filename() << endl;
        }
    }
    else { cout << "Folder not already yet\n"; }
    fisy::path copy = fpath / "data_copy.txt";
    fisy::copy(fpath, copy, fisy::copy_options::overwrite_existing);
    cout << "File " << "copy";
    fisy::remove_all(copy);
    cout << "File " << copy << " delete\n";
    fisy::remove_all(fpath);
    cout << "Folder " << fpath << " delete\n";
}

