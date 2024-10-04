#include <sqlite3.h>
#include <stdio.h>

int sqliteExample() {
    const char* filePath = "C:\\Users\\user\\Documents\\SQLite\\Local_SQLite.db"; // SQLite 파일 경로
    sqlite3* connection; // DB Connection
    sqlite3_stmt* response; // DB Query 결과

    #pragma region SQLite 연결
    if (sqlite3_open(filePath, &connection) != 0) {
        printf("File open failed.\n");
        sqlite3_close(connection);
        return 1;
    }
    #pragma endregion

    printf("Something has done\n");

    return 0;
}

int main() {
    sqliteExample();
    return 0;
}