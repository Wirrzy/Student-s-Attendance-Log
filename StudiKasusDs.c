//STUDI KASUS DATA STRUCTURE\\\
//NAMA - Perwiraputra\\\
//NIM - 2501962832\\\
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

///NODE FOR THE TREE
struct node {
    char name[25];
    char attendance[30];
    double value;
    struct node *left;
    struct node *right;
};
///CREATE NEWNODE FOR THE TREE
struct node *createNewNode(double value, char name[25]){
    char absen[30];
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct tm *Sys_T;
    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);

    printf("Name : ");
    getchar();
    scanf("%[^\n]", name);
    printf("NIM : ");
    scanf("%lf", &value);
    printf("Attendance time : %s\n", asctime(Sys_T));

    
    strcpy(newNode->name, name);
    strcpy(absen, asctime (Sys_T));
    strcpy(newNode->attendance, absen);
    newNode->value = value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}
///INSERT TREE THE KEY AND NIM
struct node *insert(double value, struct node *root, char name[25]){
    if(root == NULL){ 
        return createNewNode(value, name);
    }
    else if(value > root->value){ 
        root->right = insert(value, root->right, name);
    }
    else{ 
        root->left = insert(value, root->left, name);
    }
    return root;
}
///PRINT IN ORDER(FROM THE SMALLEST NIM)
void printInOrder(struct node *root){
    if(root != NULL){
        printInOrder(root->left);
        printf("|   %s    |    %.0lf   |  %s  \n", root->name, root->value, root->attendance);
        printInOrder(root->right);
    }
}

///SEARCHING IN TREE BASED ON KEY NIM
void search(struct node* root, double key){
    if(root == NULL){
        printf("\n%.0f is not present!\n", key);
    }
    if(root->value == key){
        printf("Data Found!\n");
        printf("\nName : %s\nNIM : %.0lf\nAttendance time : %s\n", root->name, root->value, root->attendance);
        return;
    }
    if(key < root->value){ 
        return search(root->left, key);
    }
    else{ 
        return search(root->right, key);
    }
}
///MAIN FUNCTION
int main(){
    int opt;
    double key, val;
    char name[25];
    ///CREATING ROOT
    struct node *root = NULL; 

    do{
        system("cls");
        printf("-----------ATTENDANCE MENU ------------\n");
        printf("1. Attendance Input \n");
        printf("2. Student Attendance \n");
        printf("3. Search Student Data\n");
        printf("4. EXIT\n");
        printf("---------------------------------\n");
        scanf("%d", &opt);
        switch (opt){
        case 1:
            root = insert(val, root, name); ///INPUTING DATA INTO THE TREE
            printf("Attendance Data saved!\n");
            getch();
            break;
            
        case 2:
            printf("| Name\t| NIM\t| Attendance time\t|\n");
            printInOrder(root);
            getch();
            break;
            
        case 3:
            printf("Input Student NIM For search : ");
            scanf("%lf", &key);
            search(root, key);
            getch();
            break;
            
        default: 
            break;
        }
    }while(opt != 4);
    return 0;
}
