#include <stdio.h>
#include <string.h>

#define MAX 50

char backStack[MAX][50];
char forwardStack[MAX][50];
char bookmarks[MAX][50];
char lastClosedPage[50];

int topBack = -1, topForward = -1, topBookmark = -1;

char currentPage[50] = "Home";

// ---------------- STACK BASIC FUNCTIONS ----------------
void pushBack(char page[]) {
    if (topBack < MAX - 1)
        strcpy(backStack[++topBack], page);
}

void pushForward(char page[]) {
    if (topForward < MAX - 1)
        strcpy(forwardStack[++topForward], page);
}

char* popBack() {
    if (topBack >= 0)
        return backStack[topBack--];
    return NULL;
}

char* popForward() {
    if (topForward >= 0)
        return forwardStack[topForward--];
    return NULL;
}

// ---------------- MAIN FEATURES ----------------
void visitNewSite() {
    char site[50];
    printf("Enter website URL: ");
    scanf("%s", site);

    pushBack(currentPage);
    strcpy(currentPage, site);
    strcpy(lastClosedPage, "");
    topForward = -1;

    printf("? Browsing: %s\n", currentPage);
}

void goBack() {
    if (topBack < 0) {
        printf("? No pages in Back history.\n");
        return;
    }
    pushForward(currentPage);
    strcpy(currentPage, popBack());
    printf("? Now browsing: %s\n", currentPage);
}

void goForward() {
    if (topForward < 0) {
        printf("? No pages in Forward history.\n");
        return;
    }
    pushBack(currentPage);
    strcpy(currentPage, popForward());
    printf("? Now browsing: %s\n", currentPage);
}

void addBookmark() {
    if (topBookmark < MAX - 1) {
        strcpy(bookmarks[++topBookmark], currentPage);
        printf("? Added to bookmarks: %s\n", currentPage);
    }
}

void showBookmarks() {
    int i;
    if (topBookmark < 0) {
        printf("? No bookmarks saved.\n");
        return;
    }
    printf("\n?? BOOKMARKS:\n");
    for (i = 0; i <= topBookmark; i++)
        printf("%d) %s\n", i + 1, bookmarks[i]);
}

void searchHistory() {
    char key[50];
    int found = 0, i;
    printf("Enter website to search: ");
    scanf("%s", key);

    if (strcmp(currentPage, key) == 0) found = 1;

    for (i = 0; i <= topBack; i++)
        if (strcmp(backStack[i], key) == 0) found = 1;

    for (i = 0; i <= topForward; i++)
        if (strcmp(forwardStack[i], key) == 0) found = 1;

    if (found)
        printf("?? '%s' was found in history.\n", key);
    else
        printf("? '%s' not found in history.\n", key);
}

void closeCurrent() {
    strcpy(lastClosedPage, currentPage);
    printf("? Closed page: %s\n", currentPage);

    if (topBack >= 0)
        strcpy(currentPage, popBack());
    else
        strcpy(currentPage, "Home");
}

void reopenLastClosed() {
    if (strlen(lastClosedPage) == 0) {
        printf("? No recently closed page.\n");
        return;
    }
    pushBack(currentPage);
    strcpy(currentPage, lastClosedPage);
    printf("? Reopened last closed page: %s\n", currentPage);
    strcpy(lastClosedPage, "");
}

void exportHistory() {
    FILE *f = fopen("BrowsingHistory.txt", "w");
    int i;

    fprintf(f, "Current Page: %s\n\n", currentPage);

    fprintf(f, "Back History:\n");
    for (i = topBack; i >= 0; i--)
        fprintf(f, "%s\n", backStack[i]);

    fprintf(f, "\nForward History:\n");
    for (i = topForward; i >= 0; i--)
        fprintf(f, "%s\n", forwardStack[i]);

    fprintf(f, "\nBookmarks:\n");
    for (i = 0; i <= topBookmark; i++)
        fprintf(f, "%s\n", bookmarks[i]);

    fclose(f);
    printf("?? Browsing history exported successfully.\n");
}

void showStatus() {
    int i;

    printf("\n--------------------------------------------\n");
    printf("?? Current Page      : %s\n", currentPage);

    printf("? Back History      : ");
    if (topBack < 0) printf("None");
    else {
        for (i = topBack; i >= 0; i--)
            printf("%s%s", backStack[i], (i > 0 ? " ? " : ""));
    }
    printf("\n");

    printf("? Forward History   : ");
    if (topForward < 0) printf("None");
    else {
        for (i = topForward; i >= 0; i--)
            printf("%s%s", forwardStack[i], (i > 0 ? " ? " : ""));
    }
    printf("\n--------------------------------------------\n");
}

// ---------------- MAIN PROGRAM ----------------
int main() {
    int choice;

    while (1) {
        printf("\n================= BROWSER MENU =================\n");
        printf("1. Visit New Website\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Add Bookmark\n");
        printf("5. Show Bookmarks\n");
        printf("6. Search History\n");
        printf("7. Close Current Page\n");
        printf("8. Reopen Last Closed Page\n");
        printf("9. Export Browsing History\n");
        printf("10. Show Status\n");
        printf("11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: visitNewSite(); break;
            case 2: goBack(); break;
            case 3: goForward(); break;
            case 4: addBookmark(); break;
            case 5: showBookmarks(); break;
            case 6: searchHistory(); break;
            case 7: closeCurrent(); break;
            case 8: reopenLastClosed(); break;
            case 9: exportHistory(); break;
            case 10: showStatus(); break;
            case 11: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}

