
#include <iostream>
#include <sys/stat.h>
#include <ctime>

using namespace std;

int main() {

    struct stat s;

    if (stat("test.txt", &s) == 0) {

        cout << "File Size: " << s.st_size << " bytes" << endl;
        cout << "Inode Number: " << s.st_ino << endl;
        cout << "Device ID: " << s.st_dev << endl;
        cout << "Number of Links: " << s.st_nlink << endl;
        cout << "User ID: " << s.st_uid << endl;
        cout << "Group ID: " << s.st_gid << endl;
        cout << "Block Size: " << s.st_blksize << endl;
        cout << "Number of Blocks: " << s.st_blocks << endl;

        cout << "Last Access Time: " << ctime(&s.st_atime);
        cout << "Last Modification Time: " << ctime(&s.st_mtime);
        cout << "Last Status Change Time: " << ctime(&s.st_ctime);

    } else {
        cout << "File not found!" << endl;
    }

    return 0;
}
