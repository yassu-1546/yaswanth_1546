#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transport {
    int id;
    char driverName[50];
    char route[100];
    float distance;
};

void addRecord() {
    FILE *fp = fopen("transport.dat", "ab");
    struct Transport t;

    printf("Enter Transport ID: ");
    scanf("%d", &t.id);

    printf("Enter Driver Name: ");
    scanf(" %[^\n]", t.driverName);

    printf("Enter Route: ");
    scanf(" %[^\n]", t.route);

    printf("Enter Distance (km): ");
    scanf("%f", &t.distance);

    fwrite(&t, sizeof(t), 1, fp);
    fclose(fp);

    printf("Record added successfully!\n");
}

void displayRecords() {
    FILE *fp = fopen("transport.dat", "rb");
    struct Transport t;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-30s %-10s\n", "ID", "Driver Name", "Route", "Distance");
    printf("--------------------------------------------------------------------------\n");

    while (fread(&t, sizeof(t), 1, fp)) {
        printf("%-10d %-20s %-30s %-10.2f\n", t.id, t.driverName, t.route, t.distance);
    }

    fclose(fp);
}

void searchRecord() {
    FILE *fp = fopen("transport.dat", "rb");
    struct Transport t;
    int id, found = 0;

    printf("Enter Transport ID to search: ");
    scanf("%d", &id);

    while (fread(&t, sizeof(t), 1, fp)) {
        if (t.id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nDriver: %s\nRoute: %s\nDistance: %.2f km\n",
                   t.id, t.driverName, t.route, t.distance);
            found = 1;
            break;
        }
    }

    if (!found) printf("Record not found.\n");

    fclose(fp);
}

void updateRecord() {
    FILE *fp = fopen("transport.dat", "rb+");
    struct Transport t;
    int id, found = 0;

    printf("Enter Transport ID to update: ");
    scanf("%d", &id);

    while (fread(&t, sizeof(t), 1, fp)) {
        if (t.id == id) {
            printf("Enter new Route: ");
            scanf(" %[^\n]", t.route);
            printf("Enter new Distance (km): ");
            scanf("%f", &t.distance);

            fseek(fp, -sizeof(t), SEEK_CUR);
            fwrite(&t, sizeof(t), 1, fp);

            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("Record not found.\n");

    fclose(fp);
}

void deleteRecord() {
    FILE *fp = fopen("transport.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Transport t;
    int id, found = 0;

    printf("Enter Transport ID to delete: ");
    scanf("%d", &id);

    while (fread(&t, sizeof(t), 1, fp)) {
        if (t.id == id) {
            found = 1;
            continue;
        }
        fwrite(&t, sizeof(t), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("transport.dat");
    rename("temp.dat", "transport.dat");

    if (found)
        printf("Record deleted successfully!\n");
    else
        printf("Record not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Transport Management System ---\n");
        printf("1. Add Transport Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Update Transport Record\n");
        printf("5. Delete Transport Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
