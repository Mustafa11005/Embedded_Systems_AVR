#include <stdio.h>
#include <stdlib.h>
#include "STDTYPES.h"
#include <string.h>
#include <stdbool.h>

u8 Exit = 0;
u8 rejf = 0;

typedef struct node{
    char ID[25];
    char name[100];
    u16 age;
    char gender[7];
    u8 index;
    u16 record[100];
    /*
    f1 ---> 2:00 pm to 2:30 pm
    f2 ---> 2:30 pm to 3:00 pm
    f3 ---> 3:00 pm to 3:30 pm
    f4 ---> 4:00 pm to 4:30 pm
    f5 ---> 4:30 pm to 5:00 pm
    */
    struct node* next;
}node;

typedef struct slots_G{
    char regions[19];
    u8 index;
    u8 deleted;
    u8 pos;
    struct slots_G* next_G;
}slots_G;

node* head = NULL;
node* sp;
slots_G* head_G = NULL;

void Edit_Patient_I(char *ID);
void Reservation_Options_View_R(void);
void Cancel_Reserved_Slot_R(char *ID);
void Add_At_End_I();
void Edit_Patient_I(char *ID);
void View_Patient_IR(char* ID);
void Delete_I(char* ID);
void Menu_5(char* ID);
void Change_Reserved_Slot_R(char *ID);
void Menu_2();
void Menu_8();
void History(char* ID);
void Menu_4();
void Menu_6(char* ID);
bool Search_I(char* ID);

bool Check_ID_INT(char* ID){
        for(int i = 0 ; i < strlen(ID) ; ++i){
            if(ID[i] < '0' || ID[i] > '9'){
                return true;
            }
        }
    return false;

}

bool Password(){
    u8 limit = 0;
    u16 pass;
    printf("---> Password:");
    scanf(" %hi", &pass);
    getchar();
    if (pass == 1234) {
        return true;
    }
    else {
        while (1) {
            if (limit == 2) { break; }
            printf("Try again\nPassword:");
            scanf(" %hi", &pass);
            getchar();
            if (pass == 1234) {
                return true;
            }
            limit++;
        }
        return false;
    }
}

bool Reservation_Test(){
    slots_G* temp_G = head_G;
    for(int i = 0 ; i < 5 ; ++i){
        if(temp_G -> deleted == 1){
            return true;
        }
        else{
            temp_G = temp_G -> next_G;
        }
    }
    return false;
}

void Add_At_End_G(){
    slots_G* slot_1 = (slots_G *) malloc(sizeof(slots_G));
    strcpy(slot_1 -> regions, "2:00 pm to 2:30 pm");
    slot_1 -> index = 0;
    slot_1 -> deleted = 0;
    slot_1 -> pos = 1;
    slot_1 -> next_G = NULL;

    slots_G* slot_2 = (slots_G *) malloc(sizeof(slots_G));
    strcpy(slot_2 -> regions, "2:30 pm to 3:00 pm");
    slot_2 -> index = 1;
    slot_2 -> deleted = 0;
    slot_2 -> pos = 2;
    slot_2 -> next_G = NULL;

    slots_G* slot_3 = (slots_G *) malloc(sizeof(slots_G));
    strcpy(slot_3 -> regions, "3:00 pm to 3:30 pm");
    slot_3 -> index = 2;
    slot_3 -> deleted = 0;
    slot_3 -> pos = 3;
    slot_3 -> next_G = NULL;

    slots_G* slot_4 = (slots_G *) malloc(sizeof(slots_G));
    strcpy(slot_4 -> regions, "4:00 pm to 4:30 pm");
    slot_4 -> index = 3;
    slot_4 -> deleted = 0;
    slot_4 -> pos = 4;
    slot_4 -> next_G = NULL;

    slots_G* slot_5 = (slots_G *) malloc(sizeof(slots_G));
    strcpy(slot_5 -> regions, "4:30 pm to 5:00 pm");
    slot_5 -> index = 4;
    slot_5 -> deleted = 0;
    slot_5 -> pos = 5;
    slot_5 -> next_G = NULL;

    head_G = slot_1;
    slot_1 -> next_G = slot_2;
    slot_2 -> next_G = slot_3;
    slot_3 -> next_G = slot_4;
    slot_4 -> next_G = slot_5;

} // Initialize slots

void Add_Specific_Pos_G(u8 pos_G){
    if (head_G == NULL) {
        printf("List is empty\n");
        return;
    }

    slots_G* temp_G = head_G;
    for (int i = 1; temp_G != NULL && i < pos_G; i++) {
        temp_G = temp_G -> next_G;
    }

    if (temp_G == NULL) {
        printf("Position out of range\n");
        return;
    }

    temp_G -> deleted = 0;
} // After slot deleted return back to place

void Delete_G(u8 pos_G) {
    if (head_G == NULL) {
        printf("List is empty\n");
        return;
    }

    slots_G* temp_G = head_G;
    for (int i = 1; temp_G != NULL && i < pos_G; i++) {
        temp_G = temp_G -> next_G;
    }

    if (temp_G == NULL) {
        printf("Position out of range\n");
        return;
    }

    temp_G -> deleted = 1;
} // deletes slot at certain position after reserving its region for a patient

int Get_List_Size_IG(u8 IoG){
    int size = 0;
    if(IoG == 1) {
        node *temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
    } else {
        slots_G *temp_G = head_G;
        while (temp_G != NULL) {
            if(temp_G -> deleted == 0) {
                size++;
            }
            temp_G = temp_G->next_G;
        }
    }
    return size;
} // number of patients (1) OR regions (2)

bool Search_I(char* ID){
    node* temp = head;
    do {
        if(!strcmp(temp -> ID, ID)){
            sp = temp;
            return true;
        }
        else{
            temp = temp -> next;
        }
    }while(temp != NULL);
    return false;
}  // creates a pointer sp for the desired node according to ID and checks if ID exist

bool Check_ID_I(char* ID){
    node* temp = head;
    if(head != NULL) {
        for (int i = 0; i < Get_List_Size_IG(1); i++) {
            if (!strcmp(ID, temp->ID)) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    return false;
} // Checks if ID exist

bool Check_Gender_I(){
    u8 gc;
    printf("Choose gender:\n1. Male\n2. Female\n");
    scanf(" %hhu", &gc);
    getchar();
    switch (gc) {
        case 1:
            return true;
        case 2:
            return false;
        default:
            printf("\nPlease enter a valid gender choice\n");
            Check_Gender_I();
            break;
    }
    return false;
} // Menu for choosing Gender

void View_Current_Reserved_R(char* ID);

void View_Patients_I(){
    if(head != NULL){
        u16 num = 1;
        node* temp = head;
        do {
            printf("- Patient (%hi):\n", num);
            printf("Name: %s\nAge: %i\nGender: %s\nID: %s\n", temp->name, temp->age, temp->gender, temp->ID);
            View_Current_Reserved_R(temp -> ID);
            printf("\n");
            ++num;
            temp = temp -> next;
        } while (temp != NULL);
    }
    else{
        printf("\nNo patients registered\n\n");
    }
}

void Menu_1(){
    if(Exit){
        return;
    }
    u8 ch;
    printf("---> Choose mode:\n1. Admin\n2. User\n3. Exit\n");
    scanf(" %hhu", &ch);
    getchar();
    switch (ch) {
        case 1:
            if(Password()){
                Menu_2();
            }
            else{
                return;
            }
            break;
        case 2:
            Menu_8();
            break;
        case 3:
            Exit = 1;
            return;
        default:
            printf("Please choose a valid option\n");
            Menu_1();
            break;

    }

}

void Menu_2(){
    if(Exit){
        return;
    }
    u8 ch;
    printf("\n---> Choose of the following options:\n1. Add new patient\n2. Edit patient record\n3. View all patients\n4. Delete patient record\n5. Edit reservation Status\n6. Back\n");
    scanf(" %hhu", &ch);
    getchar();
    switch (ch) {
        case 1:
            printf("\n");
            Add_At_End_I();
            if(rejf){
                rejf = 0;
            }
            else {
                printf("Patient added successfully\n");
            }
            Menu_2();
            break;
        case 2:
            if(head == NULL){
                printf("No patients registered\n");
                Menu_2();
            }
            else {
                printf("\n");
                char ID[25];
                printf("---> ID:");
                fgets(ID, 25, stdin);
                ID[strcspn(ID, "\n")] = 0;
                Edit_Patient_I(ID);
            }
            break;
        case 3:
            printf("\n");
            View_Patients_I();
            Menu_2();
            break;
        case 4:
            if(head == NULL){
                printf("No patients registered\n");
                Menu_2();
            }
            else {
                printf("\n");
                char IDD[25];
                printf("---> ID:");
                fgets(IDD, 25, stdin);
                IDD[strcspn(IDD, "\n")] = 0;
                Delete_I(IDD);
            }
            break;
        case 5:
            if(head == NULL){
                printf("No patients registered\n");
                Menu_2();
            }
            else {
                printf("\n");
                Menu_4();
            }
            break;
        case 6:
            printf("\n");
            Menu_1();
            break;
        default:
            printf("\n");
            printf("Please choose a valid option\n");
            Menu_2();
            break;
    }
}

void Menu_3(){
    if(Exit){
        return;
    }
    u8 ce;
    printf("\n---> Choose The information you want to edit:\n1. Name\n2. Age\n3. Gender\n4. Back\n");
    scanf(" %hhu", &ce);
    getchar();
    switch (ce) {
        case 1:
            printf("\n");
            printf("---> Name:");
            fgets(sp -> name, 100, stdin);
            sp -> name[strcspn(sp -> name, "\n")] = 0;
            printf("Name changed successfully\n");
            Menu_3();
            break;
        case 2:
            printf("\n");
            printf("---> Age:");
            scanf(" %hi", &sp -> age);
            printf("Age changed successfully\n");
            Menu_3();
            break;
        case 3:
            printf("\n");
            if(Check_Gender_I()){
                strcpy(sp -> gender, "Male");
            }
            else{
                strcpy(sp -> gender, "Female");
            }
            printf("Gender changed successfully\n");
            Menu_3();
            break;
        case 4:
            Menu_2();
            return;
            /*
            printf("\n");
            char ID[25];
            printf("---> ID:");
            fgets(ID, 25, stdin);
            ID[strcspn(ID, "\n")] = 0;
            if(Check_ID_I(ID)){
                printf("\nEdit rejected: Repeated ID\n");
            }
            else {
                strcpy(sp -> ID, ID);
                printf("ID changed successfully\n");
            }
            Menu_3();
            break;
             */
        default:
            printf("\nPlease enter a valid gender choice\n");
            Menu_3();
            break;
    }
} // Menu for editing basic info

void Menu_4(){
    if(Exit){
        return;
    }
    u8 ch;
    printf("---> Choose of the following options:\n1. View available slots\n2. Reserve slot\n3. Change reservation slot\n4. Cancel reservation\n5. Back\n");
    scanf(" %hhu", &ch);
    getchar();
    switch (ch) {
        case 1:
            printf("---> Available slots:\n");
            Reservation_Options_View_R();
            printf("\n");
            Menu_4();
            break;
        case 2:
            char ID[25];
            printf("---> ID:");
            fgets(ID, 25, stdin);
            ID[strcspn(ID, "\n")] = 0;
            Menu_5(ID);
            Menu_4();
            break;
        case 3:
            char IDD[25];
            printf("---> ID:");
            fgets(IDD, 25, stdin);
            IDD[strcspn(IDD, "\n")] = 0;
            Change_Reserved_Slot_R(IDD);
            Menu_4();
            break;
        case 4:
            char IDDD[25];
            printf("---> ID:");
            fgets(IDDD, 25, stdin);
            IDDD[strcspn(IDDD, "\n")] = 0;
            Cancel_Reserved_Slot_R(IDDD);
            Menu_4();
            break;
        case 5:
            Menu_2();
            break;
        default:
            printf("Please choose a valid option\n");
            Menu_4();
            break;

    }

}

void Check_Edit_EC_I(){
    if(Exit){
        return;
    }
    u8 ec;
    printf("---> This ID doesn't exist\n1. Try again\n2. Back\n");
    scanf(" %hhu", &ec);
    getchar();
    if(ec == 1) {
        char ID[25];
        printf("---> ID:");
        fgets(ID, 25, stdin);
        Edit_Patient_I(ID);
    }
    else if(ec == 2){
        Menu_2();
        return;
    }
    else{
        printf("\nPlease enter a valid option\n");
        Check_Edit_EC_I();
    }
}  // Sub-Menu for ID existence to avoid repeated ones

void Check_Delete_EC_I(){
    if(Exit){
        return;
    }
    u8 ec;
    printf("---> This ID doesn't exist\n1. Try again\n2. Back\n");
    scanf(" %hhu", &ec);
    getchar();
    if(ec == 1) {
        char ID[25];
        printf("---> ID:");
        fgets(ID, 25, stdin);
        Delete_I(ID);
    }
    else if(ec == 2){
        Menu_2();
        return;
    }
    else{
        printf("\nPlease enter a valid option\n");
        Check_Delete_EC_I();
    }
}  // Sub-Menu for ID existence to avoid repeated ones

void Check_View_EC_I(){
    if(Exit){
        return;
    }
    u8 ec;
    printf("---> This ID doesn't exist\n1. Try again\n2. Back\n");
    scanf(" %hhu", &ec);
    getchar();
    if(ec == 1) {
        char ID[25];
        printf("---> ID:");
        fgets(ID, 25, stdin);
        View_Patient_IR(ID);
    }
    else if(ec == 2){
        Menu_8();
        return;
    }
    else{
        printf("\nPlease enter a valid option\n");
        Check_View_EC_I();
    }
}  // Sub-Menu for ID existence to avoid repeated ones

void Check_History_EC_I(){
    if(Exit){
        return;
    }
    u8 ec;
    printf("---> This ID doesn't exist\n1. Try again\n2. Back\n");
    scanf(" %hhu", &ec);
    getchar();
    if(ec == 1) {
        char ID[25];
        printf("---> ID:");
        fgets(ID, 25, stdin);
        History(ID);
    }
    else if(ec == 2){
        Menu_8();
        return;
    }
    else{
        printf("\nPlease enter a valid option\n");
        Check_History_EC_I();
    }
}  // Sub-Menu for ID existence to avoid repeated ones

void Check_Change_EC_I(){
    if(Exit){
        return;
    }
    u8 ec;
    printf("---> This ID doesn't exist\n1. Try again\n2. Back\n");
    scanf(" %hhu", &ec);
    getchar();
    if(ec == 1) {
        char ID[25];
        printf("---> ID:");
        fgets(ID, 25, stdin);
        Change_Reserved_Slot_R(ID);
    }
    else if(ec == 2){
        Menu_4();
        return;
    }
    else{
        printf("\nPlease enter a valid option\n");
        Check_Change_EC_I();
    }
}  // Sub-Menu for ID existence to avoid repeated ones

void View_Current_Reserved_R(char* ID) {
    if(Exit){
        return;
    }
    if (Search_I(ID)) {
        if (sp -> index == 6){
            printf("No reserved slots\n");
        }
        else {
            slots_G* temp_G = head_G;
            for (int i = 0; i < 5; ++i) {
                if (sp->index == temp_G->index) {
                    printf("Reserved slot: %s\n", temp_G->regions);
                    return;
                } else {
                    temp_G = temp_G -> next_G;
                    continue;
                }
            }
        }
    }
    else{
        printf("ID doesn't exist\n");
    }
} // To show if there is any reserved slots fo a specific ID and if Yes view

bool View_Current_Reserved_Test(char* ID) {
    if (Search_I(ID)) {
        if (sp -> index == 6){
            return false;
        }
        else {
            return true;
        }
    }
    else{
        printf("ID doesn't exist\n");
        return false;

    }

} // To show if there is any reserved slots fo a specific ID and if Yes view

void Add_At_End_I(){
    if(Exit){
        return;
    }
    node* new = (node*) malloc(sizeof(node));
    node* temp = head;
    char ID[25];
    printf("---> Fill the following information:\n");
    for(int i = 0 ; i < 100 ; i++){
        new -> record[i] = 0;
    }
    printf("Name:");
    fgets(new -> name, 100, stdin);
    new->name[strcspn(new->name, "\n")] = 0; // remove newline character
    printf("Age:");
    scanf(" %hi", &new -> age);
    getchar(); // consume newline character
    if(Check_Gender_I()){
        strcpy(new->gender, "Male");
    }
    else{
        strcpy(new->gender, "Female");
    }
    printf("ID:");
    fgets(ID, 25, stdin);
    ID[strcspn(ID, "\n")] = 0;

    for(int i = 0 ; i < 5 ; ++i) {
        new -> index = 6;
    }
    if(Check_ID_INT(ID)){
        printf("ID should contain numbers only\nRegister failed\n");
        rejf = 1;
        free(new);
        return;
    }
    if(Check_ID_I(ID)){
        printf("\nRegister rejected: Repeated ID\n");
        rejf = 1;
        free(new);
        return;
    }
    else {
        strcpy(new->ID, ID);
        new->next = NULL;
        if(head == NULL){
            head = new;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new;
        }
    }
}

void Delete_I(char* ID) {
    if(Exit){
        return;
    }
    if (head == NULL) {
        printf("No patient registered\n");
        Menu_2();
    } else {
        node* current = head;
        node* previous = NULL;

        while (current != NULL && strcmp(current->ID, ID) != 0) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            Check_Delete_EC_I();
            return;
        }

        if (previous == NULL) {
            // Node to delete is the head node
            node* temp = head;
            head = temp->next;
            free(temp);
        } else {
            // Node to delete is in the middle or end of the list
            previous->next = current->next;
            free(current);
        }
        printf("Patient deleted successfully\n");
        Menu_2();
    }
}

void Edit_Patient_I(char *ID){
    if(Exit){
        return;
    }
    if(Search_I(ID)){
        Menu_3();
    }
    else{
        Check_Edit_EC_I();
    }
}

void View_Patient_IR(char* ID){
    if(Exit){
        return;
    }
    if(head != NULL){
        if(Search_I(ID)){
            printf("Name: %s\nAge: %i\nGender: %s\nID: %s\n", sp -> name, sp -> age, sp -> gender, sp -> ID);
            View_Current_Reserved_R(ID);
        }
        else{
            Check_View_EC_I();
        }
    }
    else{
        printf("\nNo Patients registered\n");
    }
}

void Menu_5(char* ID){
    if(Exit){
        return;
    }
    if(Search_I(ID)){
        if(!View_Current_Reserved_Test(ID)) {
            printf("---> Choose one of the available slots:\n");
            u8 rc;
            Reservation_Options_View_R();
            printf("%i. Back\n", Get_List_Size_IG(2) + 1);
            scanf(" %hhu", &rc);
            getchar();
            if (rc > Get_List_Size_IG(2) + 1) {
                printf("Please choose a valid option\n");
                Menu_5(ID);
            } else if (rc == Get_List_Size_IG(2) + 1) {
                Menu_4();
            } else {
                slots_G *temp_G = head_G;
                u8 limit = 0;
                for (int i = 1; i <= 5; ++i) {
                    if (temp_G->deleted == 0) {
                        ++limit;
                        if (limit == rc) {
                            sp->index = temp_G->index;
                            for (int j = 0; j < 100; j++) {
                                if (sp->record[j] == 0) {
                                    sp->record[j] = (temp_G->index + 1);
                                    break;
                                } else {
                                    continue;
                                }
                            }
                            Delete_G(i);
                        } else {
                            temp_G = temp_G->next_G;
                        }
                    } else {
                        temp_G = temp_G->next_G;
                    }
                }
            }
        }
        else{
            printf("Patient already has a reservation\n");
        }
    }
    else{
        printf("ID doesn't exist\n");
        return;
    }
}

void Menu_7(char* ID){
    if(Exit){
        return;
    }
    if(Search_I(ID)){
        if(!View_Current_Reserved_Test(ID)) {
            printf("---> Choose one of the available slots:\n");
            u8 rc;
            Reservation_Options_View_R();
            printf("%i. Back\n", Get_List_Size_IG(2) + 1);
            scanf(" %hhu", &rc);
            getchar();
            if (rc > Get_List_Size_IG(2) + 1) {
                printf("Please choose a valid option");
                Menu_7(ID);
            } else if (rc == Get_List_Size_IG(2) + 1) {
                Menu_6(ID);
                return;
            } else {
                slots_G *temp_G = head_G;
                u8 limit = 0;
                for (int i = 1; i <= 5; ++i) {
                    if (temp_G->deleted == 0) {
                        ++limit;
                        if (limit == rc) {
                            sp->index = temp_G->index;
                            for (int j = 0; j < 100; j++) {
                                if (sp->record[j] == 0) {
                                    sp->record[j] = (temp_G->index + 6);
                                    break;
                                } else {
                                    continue;
                                }
                            }
                            for (int j = 0; j < 100; j++) {
                                if (sp->record[j] == 0) {
                                    sp->record[j] = (temp_G->index + 1);
                                    break;
                                } else {
                                    continue;
                                }
                            }
                            Delete_G(i);
                        } else {
                            temp_G = temp_G->next_G;
                        }
                    } else {
                        temp_G = temp_G->next_G;
                    }
                }
            }
        }
        else{
            printf("Patient already has a reservation\n");
        }
    }
    else{
        printf("ID doesn't exist\n");
        return;
    }
}

void Reserve_Slot_R_Change(char* ID){
    if(Exit){
        return;
    }
    if(Search_I(ID)){
        printf("---> Which of the following slots You want to transfer to:\n");
        u8 rc;
        Reservation_Options_View_R();
        printf("%i. Back\n", Get_List_Size_IG(2)+1);
        scanf(" %hhu", &rc);
        getchar();
        if(rc > Get_List_Size_IG(2)+1){
            printf("Please choose a valid option");
            Reserve_Slot_R_Change(ID);
        }
        else if(rc == Get_List_Size_IG(2)+1){
            return; // menu (4)
        }
        else{
            slots_G* temp_G = head_G;
            u8 limit = 0;
            for(int i = 1 ; i <= 5 ; ++i){
                if(temp_G -> deleted == 0){
                    ++limit;
                    if(limit == rc){
                        Cancel_Reserved_Slot_R(ID);
                        sp -> index = temp_G -> index;
                        for(int j = 0 ; j < 100 ; j++){
                            if(sp -> record[j] == 0){
                                sp -> record [j] = (temp_G -> index + 1);
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                        Delete_G(i);
                    }
                    else{
                        temp_G = temp_G -> next_G;
                    }
                }
                else{
                    temp_G = temp_G -> next_G;
                }
            }
        }

    }
    else{
        printf("ID doesn't exist\n");
        return;
    }
}

void Menu_6(char* ID){
    if(Exit){
        return;
    }
    u8 ch;
    printf("\n1. Reserve slot\n2. Back\n");
    scanf(" %hhu", &ch);
    getchar();
    if(ch == 1){
        Menu_7(ID);
    }
    else if(ch == 2){
        Menu_4();
    }
    else{
        printf("Please choose a valid option\n");
        Menu_6(ID);

    }

}

void Change_Reserved_Slot_R(char *ID){
    if(Exit){
        return;
    }
    if(Search_I(ID)){
        if(sp -> index == 6){
            printf("%s has no reservation:", sp -> name);
            Menu_6(ID);
        }
        else{
            slots_G* temp_G = head_G;
            for(int i = 0 ; i < 5 ; i++) {
                if (sp->index == temp_G->index) {
                    printf("%s has a reservation at ", sp->name);
                    slots_G *temp2_G = head_G;
                    for (int j = 0; j < 5; ++j) {
                        if (sp->index == temp2_G->index) {
                            printf(" %s:\n", temp2_G->regions);
                            Reserve_Slot_R_Change(ID);
                            return;
                        } else {
                            temp2_G = temp2_G->next_G;
                            continue;
                        }
                    }
                }
                else{
                    temp_G = temp_G -> next_G;
                }
            }
        }
    }
    else{
        Check_Change_EC_I();
        return;
    }
    free(sp);
} // Chane to

void History(char* ID){
    if(Search_I(ID)){
        printf("%s's reservation history:\n",sp -> name);
        if(sp -> record[0] == 0){
            printf("- %s has no reservation history", sp -> name);
        }
        else {
            for (int i = 0; i < 100 && sp->record[i] != 0; i++) {
                if (sp->record[i] == 1) {
                    printf("Reservation:\n\t( 2:00 pm to 2:30 pm )");
                } else if (sp->record[i] == 2) {
                    printf("Reservation:\n\t( 2:30 pm to 3:00 pm )");
                } else if (sp->record[i] == 3) {
                    printf("Reservation:\n\t( 3:00 pm to 3:30 pm )");
                } else if (sp->record[i] == 4) {
                    printf("Reservation:\n\t( 4:00 pm to 4:30 pm )");
                } else if (sp->record[i] == 5) {
                    printf("Reservation:\n\t( 4:30 pm to 5:00 pm )");
                } else if (sp->record[i] == 6) {
                    printf("Cancellation :\n\t( 2:00 pm to 2:30 pm )");
                } else if (sp->record[i] == 7) {
                    printf("Cancellation :\n\t( 2:30 pm to 3:00 pm )");
                } else if (sp->record[i] == 8) {
                    printf("Cancellation :\n\t( 3:00 pm to 3:30 pm )");
                } else if (sp->record[i] == 9) {
                    printf("Cancellation:\n\t( 4:00 pm to 4:30 pm )");
                } else if (sp->record[i] == 10) {
                    printf("Cancellation:\n\t( 4:30 pm to 5:00 pm )");
                }
                printf("\n");
            }
        }
    }
    else{
        Check_History_EC_I();
    }
}

void Cancel_Reserved_Slot_R(char *ID){
    if(Search_I(ID)){
        if(View_Current_Reserved_Test(ID)) {
            slots_G *temp_G = head_G;
            for (int i = 0; i < 5; i++) {
                if (sp->index == temp_G->index) {
                    sp->index = 6;
                    for (int j = 0; j < 100; j++) {
                        if (sp->record[j] == 0) {
                            sp->record[j] = (temp_G->index + 6);
                            break;
                        } else {
                            continue;
                        }
                    }
                    Add_Specific_Pos_G(temp_G->pos);
                    return;
                } else {
                    temp_G = temp_G->next_G;
                }
            }
        }
        else{
            printf("This ID has no reservations\n");
        }
    }
    else{
        printf("ID doesn't exist\n");
        return;
    }

}

void Reservation_Options_View_R(){
    if(Exit){
        return;
    }
    u8 itt = 1;
    slots_G* temp_G = head_G;
    for(int i = 0 ; i < 5 ; i++){
        if(temp_G -> deleted == 0){
            printf("%hhu. %s", itt, temp_G -> regions);
            printf("\n");
            ++itt;
            temp_G = temp_G -> next_G;
        }
        else{
            temp_G = temp_G -> next_G;
            continue;
        }
    }
}

void View_Todays_Res(){
    node* temp = head;
    if(Reservation_Test()) {
        for (int i = 0; i < Get_List_Size_IG(1); ++i) {
            if (temp->index != 6) {
                printf("Name: %s\nID: %s\n", temp -> name ,temp->ID);
                View_Current_Reserved_R(temp->ID);
                temp = temp->next;
            } else {
                temp = temp->next;
                continue;
            }
        }
    }
    else{
        printf("No reservation today\n");
    }
}

void Menu_8(){
    if(Exit){
        return;
    }
    u8 ch;
    printf("\n---> Choose of the following options:\n1. View patient record\n2. View patient Reservation history\n3. View today's reservations\n4. Back\n");
    scanf(" %hhu", &ch);
    getchar();
    switch (ch) {
        case 1:
            if(head == NULL){
                printf("\nNo patients registered\n");
                Menu_8();
            }
            else {
                printf("\n");
                char ID[25];
                printf("---> ID:");
                fgets(ID, 25, stdin);
                ID[strcspn(ID, "\n")] = 0; // remove newline character
                printf("\n");
                View_Patient_IR(ID);
                Menu_8();
            }
            break;
        case 2:
            if(head == NULL){
                printf("\nNo patients registered\n");
                Menu_8();
            }
            else {
                printf("\n");
                char IDD[25];
                printf("---> ID:");
                fgets(IDD, 25, stdin);
                IDD[strcspn(IDD, "\n")] = 0;
                printf("\n");
                History(IDD);
                printf("\n");
                Menu_8();
            }
            break;
        case 3:
            if(head == NULL){
                printf("\nNo slots reserved\n");
                Menu_8();
            }
            else {
                printf("\n");
                View_Todays_Res();
                Menu_8();
            }
            break;
        case 4:
            printf("\n");
            Menu_1();
            break;
        default:
            printf("Please choose a valid option\n");
            Menu_8();
            break;

    }

}

int main(void) {
    printf("\t\t\tWelcome to our clinic system\n\n");
    Add_At_End_G();
    Menu_1();
    return 0;
}
