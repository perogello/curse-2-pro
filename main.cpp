#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <clocale>
#include <windows.h>
#include <iostream>

using namespace std;

enum Colors { hide=0,blue=1,green=2,cyan=3,red=4};
enum Colors2 { magenta=5,yellow=6,white=7,grey=8,bblack=8,gray=8};

void coutc(int color, char* output){
    HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( handle, color);
    cout<< output;
    SetConsoleTextAttribute( handle, white);
}

struct elementWord {
    char *word;
    struct elementWord *nextPointerW;
} *pointerWord, *bufferWord;

struct elementSentence {
    struct elementWord *Word;
    struct elementSentence *nextPointerS;
    struct elementSentence *previousPointer;
} *pointerSentence, *bufferSentence;

struct elementText {
    struct elementSentence *Sentence;
    struct elementText *nextPointerT;
} *firstPointer, *pointer;


void mainMenu();
void menu1();
void menu2();
void menu3();
void workWithSequence();


void textList();
void sentenceList();
void wordsList();


//Функции для работы с последовательностью
void makeSequenceEmpty();
void skipSequenceItem();
void addLastElement();
void showSequenceElement();
void readSequenceItem();
void changeSequenceElement();
void setEndSequencePtr();
void outputSequence();
void quitSequence();

//Функции для работы с двухсвязным списком слов
void makeSentenceListEmpty();
void addAfterPointerSentence();
void addBEforePointerSentence();
void SentenceListPtrUp();
void SentenceListPtrDown();
void beginSentenceListPtr();
void endSentenceListPtr();
void takeElementSentenceListPtrDoun();
void takeElementSentenceListPtrUp();
void putElementSentenceListPtrUp();
void putElementSentenceListPtrDoun();
void deleteElementSentenceListBeforePtr();
void deleteElementSentenceListAfterPtr();
void changeElementSentenceListPtrDown();
void changeElementSentenceListPtrUp();
void outputList();

//функции для работы со списком слов
void addAfterPointerWord();
void makeWordListEmpty();
void beginWordsListPtr();
void WordsListPtrUp();
void showElementWordsListPtrUp();
void deleteElementWordsListPtrUp();
void takeElementWordsListPtrUp();
void putBufferWord();
void changeElementWordsListPtrUp();
void printWordsList();

int main()
{
    setlocale(LC_ALL,"Rus");

    firstPointer = NULL;
    bufferWord = NULL;
    bufferSentence = NULL;
    pointer = NULL;

    mainMenu();

    system("cls");
    printf("\n      Come again, User!\n");

    return 0;
}

void mainMenu()
{
    short int choice;
    printf("        Hello, User!\n\n");
    printf("Start working with sequence-(L1)-( 1 )\n");
    printf("Quit-----------------------------( 2 )\n\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    while (choice > 2 || choice < 1) {
        printf("Make your choice again rightly: ");
        scanf("%d", &choice);
    }

    switch (choice){
        case 1: {
            menu1();
            break;
        }
        case 2: {
            break;
        }
    }
}

void menu1()
{
    short int choice;

    while (choice != 9) {
        system("cls");
        printf("\n          Welcome to Text Sequence!\n\n");
        textList();
        printf(">Make the sequence empty-------------------( 1 )\n"); //Сделать посдедовательность пустой  +
        //printf(">Is the Sequence empty?--------------------( 2 )\n"); //Проверка: Посдедовательность пуста?
        printf(">Show item value---------------------------( 2 )\n"); //Показать значение очередного элемента  +
        printf(">Skip item---------------------------------( 3 )\n"); //Пропустить очередной элемент посдедовательности  +
        printf(">Read item---------------------------------( 4 )\n"); //Прочитать очередной элемент последовательности  +
        printf(">Change the value of an element------------( 5 )\n"); //Изменить значение очередного элемента  +
        if (pointer == NULL) coutc(cyan, ">Add an element to the end of the sequence-( 6 )\n"); //Добавить элемент в конец последовательности  +
        else printf(">Add an element to the end of the sequence-( 6 )\n"); //Добавить элемент в конец последовательности  +
        printf(">Set the pointer to the end of the sequence( 7 )\n"); //Установить указатель в конец последовательности  +
        //printf(">Are there any unread items?---------------( 9 )\n"); //Проверка: есть ли непрочитанные элементы?
        printf(">Output the Sequence-----------------------( 8 )\n"); //Распечатать структуру данных  +
        printf(">Quit--------------------------------------( 9 )\n"); //Закончить работу с последовательностью  +
        printf("Your choice: ");
        scanf("%d", &choice);
        while (choice > 9 || choice < 1) {
            printf("Make your choice again rightly: ");
            scanf("%d", &choice);
        }

        switch (choice){
            case 1: {
                system("cls");
                makeSequenceEmpty();
                break;
            }
            case 2: {
                system("cls");
                showSequenceElement();
                break;
            }
            case 3: {
                system("cls");
                skipSequenceItem();
                break;
            }
            case 4: {
                if (pointer != NULL) {
                    pointerSentence = pointer->Sentence;
                    system("cls");
                    menu2();
                }
                else {
                    system("cls");
                    printf("\n      You can't do it!\n\n");
                    printf("\n  Push any key to back to menu\n");
                    getch();
                }
                break;
            }
            case 5: {
                system("cls");
                changeSequenceElement();
                break;
            }
            case 6: {
                system("cls");
                addLastElement();
                break;
            }
            case 7: {
                system("cls");
                setEndSequencePtr();
                break;
            }
            case 8: {
                system("cls");
                outputSequence();
                break;
            }
        }
    }
}

void menu2()
{
    short int choice;

    while (choice != 17) {
        system("cls");
        printf("\n          Welcome to list of sentences!\n\n");
        textList();
        sentenceList();
        printf(">Make the list empty-----------------------( 1 )\n"); //Сделать список пустой  +
        //printf(">Is the list empty?------------------------( 2 )\n"); //Проверка: спиок пуст?
        printf(">Set the pointer to the top of the list----( 2 )\n"); //Устновить указатель в начало списка  +
        printf(">Set pointer to the end of the list--------( 3 )\n"); //Устновить указатель в конец списка  +
        //printf(">Is the pointer at the top of the list?----( 5 )\n"); //Проверка: указатель в начале списка?
        //printf(">Is the pointer at the end of the list?----( 6 )\n"); //Проверка: указатель в конце списка?
        printf(">Move the pointer forward------------------( 4 )\n"); //Переместить указатель вперёд  +
        printf(">Move the pointer back---------------------( 5 )\n"); //Переместить указатель назад  +
        //printf(">Show the value before the pointer---------( 9 )\n"); //Показать значение списка до указателя
        //printf(">Show the value after the pointer----------( 10 )\n"); //Показать значение списка посде указателя
        printf(">Delete the element of list before the ptr-( 6 )\n"); //Удалить элемент списка до указатедя  +
        printf(">Delete the element of list after the ptr--( 7 )\n"); //Удалить элемент списка после указатедя  +
        printf(">Take the element of list before the ptr---( 8 )\n"); //Взять элемент списка до указателя  +
        printf(">Take the element of list after the ptr----( 9 )\n"); //Взять элемент списка после указателя  +
        printf(">Copy from the buffer after the ptr--------( 10 )\n"); //Поместить скопрированный элемент списка после указателя  +
        printf(">Copy from the buffer before the ptr-------( 11 )\n"); //Поместить скопированный элемент списка ло указателя  +
        printf(">Change the value of element before the ptr( 12 )\n"); //Изменить значение элемента списка до указателя  +
        printf(">Change the value of element after the ptr-( 13 )\n"); //Изменить значение элемента списка после указателя  +
        if (pointer->Sentence == NULL) {
            coutc(cyan, ">Add the element before the pointer--------( 14 )\n");
            coutc(cyan, ">Add the element after the pointer---------( 15 )\n");
        }
        else {
            printf(">Add the element before the pointer--------( 14 )\n"); //Добавить элемент до указателя  +
            printf(">Add the element after the pointer---------( 15 )\n"); //Добавить элемент после указателя  +
        }
        printf(">Output the list---------------------------( 16 )\n"); //Распечатать структуру данных  +
        printf(">End the work with the list----------------( 17 )\n"); //Закончить работу со списком  +
        //printf(">Level Up----------------------------------( 21 )\n"); //Подняться на уровень вверх
        printf(">Level Down--------------------------------( 18 )\n"); //Опуститься на уровень вниз  +
        printf("Your choice: ");
        scanf("%d", &choice);
        while (choice > 18 || choice < 1) {
            printf("Make your choice again rightly: ");
            scanf("%d", &choice);
        }
        switch (choice) {
            case 1: {
                system("cls");
                makeSentenceListEmpty();
                break;
            }
            case 2: {
                system("cls");
                beginSentenceListPtr();
                break;
            }
            case 3: {
                system("cls");
                endSentenceListPtr();
                break;
            }
            case 4: {
                system("cls");
                SentenceListPtrUp();
                break;
            }
            case 5: {
                system("cls");
                SentenceListPtrDown();
                break;
            }
            case 6: {
                system("cls");
                deleteElementSentenceListBeforePtr();
                break;
            }
            case 7: {
                system("cls");
                deleteElementSentenceListAfterPtr();
                break;
            }
            case 8: {
                system("cls");
                takeElementSentenceListPtrDoun();
                break;
            }
            case 9: {
                system("cls");
                takeElementSentenceListPtrUp();
                break;
            }
            case 10: {
                system("cls");
                putElementSentenceListPtrUp();
                break;
            }
            case 11: {
                system("cls");
                putElementSentenceListPtrDoun();
                break;
            }
            case 12: {
                system("cls");
                changeElementSentenceListPtrDown();
                break;
            }
            case 13: {
                system("cls");
                changeElementSentenceListPtrUp();
                break;
            }
            case 14: {
                system("cls");
                addBEforePointerSentence();
                break;
            }
            case 15: {
                system("cls");
                addAfterPointerSentence();
                break;
            }
            case 16: {
                system("cls");
                outputList();
                break;
            }
            case 17: {
                pointer = firstPointer;
                break;
            }
            case 18: {
                if (pointer->Sentence != NULL) {
                    pointerWord = pointerSentence->Word;
                    system("cls");
                    menu3();
                }
                else {
                    system("cls");
                    printf("\n      You can't do it!\n\n");
                    printf("\n  Push any key to back to menu\n");
                    getch();
                }
                break;
            }
        }
    }
}

void textList()
{
    if (pointer == NULL) coutc(red ,"            The sequence is empty!\n\n");
    else {
        int i = 1;
        struct elementText *ptr;
        ptr = firstPointer;
        coutc(yellow, "\n          >Text list: ");
        while (ptr->nextPointerT != NULL) {
            if (ptr == pointer) {
                coutc(green, "Text");
                printf("%d, ", i);
            }
            else printf("Text%d, ", i);
            i++;
            ptr = ptr->nextPointerT;
        }
        if (ptr == pointer) {
                coutc(green, "Text");
                printf("%d", i);
                printf(".\n\n");
            }
        else printf("Text%d.\n\n", i);
    }
}

void sentenceList()
{
    if (pointer->Sentence == NULL) coutc(red ,"         The list of sentences is empty! ");
    else {
        int i = 1;
        struct elementSentence *ptr;
        ptr = pointer->Sentence;
        coutc(yellow, "\n          >Sentence list: ");
        while (ptr->nextPointerS != NULL) {
            if (ptr == pointerSentence) {
                coutc(green, "Sentence");
                printf("%d, ", i);
            }
            else printf("Sentence%d, ", i);
            i++;
            ptr = ptr->nextPointerS;
        }
        if (ptr == pointerSentence) {
            coutc(green, "Sentence");
            printf("%d. ", i);
        }
        else printf("Sentence%d. ", i);
    }
    coutc(yellow, ">Buffer: ");
    if (bufferSentence != NULL) coutc(green, "<FULL>\n\n");
    else coutc(red, "<EMPTY>\n\n");
}

void wordsList()
{
    if (pointerSentence->Word == NULL) coutc(red ,"          The list of words is empty! ");
    else {
        int i = 1;
        struct elementWord *ptr;
        ptr = pointerSentence->Word;
        coutc(yellow, "\n          >Words list: ");
        while (ptr->nextPointerW != NULL) {
            if (ptr == pointerWord) {
                coutc(green, ptr->word);
                printf(", ");
            }
            else printf("%s, ", ptr->word);
            i++;
            ptr = ptr->nextPointerW;
        }
        if (ptr == pointerWord) {
                coutc(green, ptr->word);
                printf(". ");
        }
        else printf("%s. ", ptr->word);
    }
    coutc(yellow, ">Buffer: ");
    if (bufferWord != NULL) coutc(green, "<FULL>\n\n");
    else coutc(red, "<EMPTY>\n\n");
}

void menu3()
{
    short int choice;

    while (choice != 9) {
        system("cls");
        printf("\n          Welcome to list of words!\n\n");
        textList();
        sentenceList();
        wordsList();
        printf(">Make the list empty-----------------------( 1 )\n"); //Сделать список пустым  +
        //printf(">Is the list empty?------------------------( 2 )\n"); //Проверка: спиок пуст?
        printf(">Set the pointer to the top of the list----( 2 )\n"); //Устновить указатель в начало списка  +
        //printf(">Is the pointer at the end of the list?----( 4 )\n"); //Проверка: указатель в конце списка?
        printf(">Move the pointer forward------------------( 3 )\n"); //Переместить указатель вперёд  +
        //printf(">Show the value after the pointer----------( 6 )\n"); //Показать значение элемента списка посде указателя
        printf(">Delete the element of list after the ptr--( 4 )\n"); //Удалить элемент списка после указатедя  +
        printf(">Take the element of list after the ptr----( 5 )\n"); //Взять элемент списка после указателя  +
        printf(">Copy from the buffer after the ptr--------( 6 )\n"); //Скопировать элемент из буффера после указателя  +
        printf(">Change the value of element after the ptr-( 7 )\n"); //Изменить значение элемента списка после указателя  +
        if (pointerSentence->Word == NULL) coutc(cyan, ">Add the element after the pointer---------( 8 )\n"); //Добавить элемент после указателя +
        else printf(">Add the element after the pointer---------( 8 )\n"); //Добавить элемент после указателя +
        //printf(">Output the list---------------------------( 11 )\n"); //Распечатать структуру данных
        printf(">End the work with the list----------------( 9 )\n"); //Закончить работу со списком  +
        printf("Your choice: ");
        scanf("%d", &choice);
        while (choice > 9 || choice < 1) {
            printf("Make your choice again rightly: ");
            scanf("%d", &choice);
        }
        switch (choice) {
            case 1: {
                system("cls");
                makeWordListEmpty();
                break;
            }
            case 2: {
                system("cls");
                beginWordsListPtr();
                break;
            }
            case 3: {
                system("cls");
                WordsListPtrUp();
                break;
            }
            case 4: {
                system("cls");
                deleteElementWordsListPtrUp();
                break;
            }
            case 5: {
                system("cls");
                takeElementWordsListPtrUp();
                break;
            }
            case 6: {
                system("cls");
                putBufferWord();
                break;
            }
            case 7: {
                system("cls");
                changeElementWordsListPtrUp();
                break;
            }
            case 8: {
                system("cls");
                addAfterPointerWord();
                break;
            }
            case 9: {
                break;
            }
        }
    }
}

void makeSequenceEmpty()
{
    if (firstPointer == NULL) {
        printf("\n      Now sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        struct elementText *toDelete, *flag;
        if (firstPointer->nextPointerT != NULL) {
            flag = firstPointer->nextPointerT;
            while (flag->nextPointerT != NULL) {
                toDelete = flag;
                free(toDelete);
                flag = flag->nextPointerT;
            }
            free(toDelete);
            free(firstPointer);
            firstPointer = NULL;
            pointer = NULL;
            pointerSentence = NULL;
            pointerWord = NULL;
        }
        else {
            free(firstPointer);
            firstPointer = NULL;
            pointer = NULL;
            pointerSentence = NULL;
            pointerWord = NULL;
        }
        printf("\n      Now sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void skipSequenceItem()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointer->nextPointerT == NULL) {
        printf("This is the last element of sequence!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else pointer = pointer->nextPointerT;
}

void showSequenceElement()
{
    if (pointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        int i = 1, j = 1;
        struct elementText *ptr;
        struct elementSentence *ptrS = pointer->Sentence;

        ptr = firstPointer;
        ptrS = pointer->Sentence;

        while (ptr != pointer) {
            ptr = ptr->nextPointerT;
            j++;
        }

        printf("Text%d\n", j);

        if (pointer->Sentence == NULL) printf("<EMPTY>\n");

        while (ptrS != NULL) {
        struct elementWord *ptrW;
            ptrW = ptrS->Word;
            printf("Sentence%d: ", i);
            if (ptrW == NULL) printf("<EMPTY>\n");
            else {
                while (ptrW->nextPointerW != NULL) {
                    printf("%s", ptrW->word);
                    printf(", ");
                    ptrW = ptrW->nextPointerW;
                }
                printf("%s.\n", ptrW->word);
            }
            ptrS = ptrS->nextPointerS;
            i++;
        }
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void readSequenceItem()
{
    if (pointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointer->Sentence == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointer->Sentence->Word == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else {

    }
}

void changeSequenceElement()
{
    if (pointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointer->Sentence == NULL) {
        printf("\nThis element is empty!");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        short int check = 0;
        int i = 1, j = 1;
        struct elementSentence *ptr;
        struct elementWord *ptrW;
        ptr = pointer->Sentence;
        ptrW = pointer->Sentence->Word;

        while (ptr->nextPointerS != NULL) {
            if (ptr->Word == NULL) {
                printf("\nSentence%d\n", j);
                printf("<EMPTY>\n");
                j++;
                ptr = ptr->nextPointerS;
                ptrW = ptr->Word;
            }
            else {
                printf("\nSentence%d\n", j);
                while (ptrW->nextPointerW != NULL) {
                    printf("\n        Enter a replacement word #%d: ", i);
                    scanf("%s", ptrW->word);
                    i++;
                    check = 1;
                    ptrW = ptrW->nextPointerW;
                }
                printf("\n        Enter a replacement word #%d: ", i);
                scanf("%s", ptrW->word);
                i = 1;
                j++;
                check = 1;
                ptr = ptr->nextPointerS;
                ptrW = ptr->Word;
            }
        }
        printf("\nSentence%d\n", j);
        if (ptr->Word == NULL) printf("<EMPTY>\n");
        else {
            while (ptrW->nextPointerW != NULL) {
                printf("\n        Enter a replacement word #%d: ", i);
                scanf("%s", ptrW->word);
                i++;
                check = 1;
                ptrW = ptrW->nextPointerW;
            }
            printf("\n        Enter a replacement word #%d: ", i);
            scanf("%s", ptrW->word);
            check = 1;
            system("cls");
        }
        if (check == 1) printf("\n\n     Text successfully replaced!");
        printf("\n    Push any key to back to menu");
        getch();
    }
}

void setEndSequencePtr()
{
    pointer = firstPointer;

    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        while (pointer->nextPointerT != NULL)  pointer = pointer->nextPointerT;
        printf("This is the last element of sequence!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void checkUnreadSequenceItems()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointer->nextPointerT == NULL) {
        printf("This is the last element of sequence!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointer->Sentence == NULL) {
        printf("\nThis element of sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointer->Sentence->Word == NULL) {
        printf("\nThis element of sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointer->nextPointerT == NULL) printf("Not enough elements to reading!\n");
    else if (pointer->nextPointerT != NULL) printf("There are unread items!\n");
}

void addLastElement()
{
    short int choice;
    struct elementText *ptr, *newText;

    if (firstPointer == NULL) {
        firstPointer = (struct elementText*)malloc(sizeof(struct elementText));
        firstPointer->nextPointerT = NULL;
        pointer = firstPointer;
        pointer->Sentence = NULL;
        pointerSentence = NULL;
        firstPointer->Sentence = NULL;
    }

    else {
        ptr = firstPointer;
        while (ptr->nextPointerT != NULL) {
            ptr = ptr->nextPointerT;
        }
        newText = (struct elementText*)malloc(sizeof(struct elementText));
        newText->nextPointerT = NULL;
        ptr->nextPointerT = newText;
        pointer = newText;
        pointer->Sentence = NULL;
        pointerSentence = NULL;
        newText->Sentence = NULL;
    }

    printf("\nStart working with Text (L2)-----( 1 )\n");
    printf("Quit-----------------------------( 2 )\n\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    while (choice > 2 || choice < 1) {
        printf("Make your choice again rightly: ");
        scanf("%d", &choice);
    }

    switch (choice){
        case 1: {
            menu2();
            break;
        }
        case 2: {
            break;
        }
    }
}



void outputSequence()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        int i = 1, j;
        struct elementText *ptr = firstPointer;

        //if (ptr->Sentence == NULL) printf("    Text1: <EMPTY>", i);

        //else {
            while(ptr != NULL) {
                struct elementSentence *ptrS = ptr->Sentence;
                j = 1;
                ptrS = ptr->Sentence;
                printf("    Text%d\n", i);
                if (ptrS == NULL) printf("<EMPTY>\n");
                else {
                    while (ptrS != NULL) {
                        struct elementWord *ptrW = ptr->Sentence->Word;
                        ptrW = ptrS->Word;
                        printf("Sentence%d: ", j);
                        if (ptrW == NULL) printf("<EMPTY>\n");
                        else {
                            while (ptrW->nextPointerW != NULL) {
                                printf("%s", ptrW->word);
                                printf(", ");
                                ptrW = ptrW->nextPointerW;
                            }
                            printf("%s.\n", ptrW->word);
                        }
                        ptrS = ptrS->nextPointerS;
                        j++;
                    }
                }
                printf("\n\n");
                ptr = ptr->nextPointerT;
                i++;
            }
        //}
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void outputList()
{
    if (pointer->Sentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        int i = 1;
        struct elementSentence *ptrS = pointer->Sentence;

        ptrS = pointer->Sentence;

                    while (ptrS != NULL) {
                        struct elementWord *ptrW;
                        ptrW = ptrS->Word;
                        printf("Sentence%d: ", i);
                        if (ptrW == NULL) printf("<EMPTY>\n");
                        else {
                            while (ptrW->nextPointerW != NULL) {
                                printf("%s", ptrW->word);
                                printf(", ");
                                ptrW = ptrW->nextPointerW;
                            }
                            printf("%s.\n", ptrW->word);
                        }
                        ptrS = ptrS->nextPointerS;
                        i++;
                    }
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void makeSentenceListEmpty()
{
     if (pointer->Sentence == NULL) {
        printf("        The list was already devastated!\n\n");
        printf("          Push any key to back to menu");
        getch();
    }
    else if (pointer->Sentence->nextPointerS == NULL)
    {
        free(pointer->Sentence);
        pointerSentence = NULL;
        pointer->Sentence = NULL;
        printf("        The list was successfully devastated!\n\n");
        printf("            Push any key to back to menu");
        getch();
    }
    else {
        struct elementSentence *flag, *toDelete;
        flag = pointer->Sentence->nextPointerS;
        while (flag->nextPointerS != NULL) {
            toDelete = flag;
            flag = flag->nextPointerS;
            free(toDelete);
        }
        free(flag);
        pointerSentence = NULL;
        pointer->Sentence = NULL;
        printf("        The list was successfully devastated!\n\n");
        printf("            Push any key to back to menu");
        getch();
    }
}

void changeElementSentenceListPtrDown()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointerSentence->previousPointer == NULL) {
        printf("       This is the first element of sentence list!\n\n");
        printf("              Push any key to back to menu");
        getch();
    }

    else {
        pointerSentence = pointerSentence->previousPointer;
        if (pointerSentence->Word == NULL) {
            printf("        This sentence is empty!\n\n");
            printf("      Push any key to back to menu");
            getch();
        }
        else {
            struct elementWord *ptr;
            int i = 1;
            ptr = pointerSentence->Word;
            while (ptr->nextPointerW != NULL) {
                printf("\n        Enter a replacement word #%d: ", i);
                scanf("%s", ptr->word);
                i++;
                ptr = ptr->nextPointerW;
            }
            printf("\n        Enter a replacement word #%d: ", i);
            scanf("%s", ptr->word);
            system("cls");
            printf("\n\n        Word successfully replaced!\n");
            printf("       Push any key to back to menu");
            getch();
        }
    }
}

void changeElementSentenceListPtrUp()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointerSentence->nextPointerS == NULL) {
        printf("        This is the last element of sentence list!\n\n");
        printf("              Push any key to back to menu");
        getch();
    }

    else {
        pointerSentence = pointerSentence->nextPointerS;
        if (pointerSentence->Word == NULL) {
            printf("        This sentence is empty!\n\n");
            printf("      Push any key to back to menu");
            getch();
        }
        else {
            struct elementWord *ptr;
            int i = 1;
            ptr = pointerSentence->Word;
            while (ptr->nextPointerW != NULL) {
                printf("\n        Enter a replacement word #%d: ", i);
                scanf("%s", ptr->word);
                i++;
                ptr = ptr->nextPointerW;
            }
            printf("\n        Enter a replacement word #%d: ", i);
            scanf("%s", ptr->word);
            system("cls");
            printf("\n\n     Sentence successfully replaced!\n");
            printf("       Push any key to back to menu");
            getch();
        }
    }
}

void takeElementSentenceListPtrDoun()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointerSentence->previousPointer == NULL) {
        printf("        This is the first element of sentence list!\n\n");
        printf("              Push any key to back to menu");
        getch();
    }

    else {
        struct elementSentence *box;
        box = pointerSentence->previousPointer;
        if (box->previousPointer == NULL) {
            bufferSentence = box;
            pointerSentence->previousPointer = NULL;
            pointer->Sentence = pointerSentence;
        }
        else {
            box = box->previousPointer;
            bufferSentence = pointerSentence->previousPointer;
            box->nextPointerS = pointerSentence;
            pointerSentence->previousPointer = box;
        }
    }
}

void takeElementSentenceListPtrUp()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointerSentence->nextPointerS == NULL) {
        printf("        This is the last element of sentence list!\n\n");
        printf("              Push any key to back to menu");
        getch();
    }

    else {
        struct elementSentence *box;
        box = pointerSentence->nextPointerS;
        if (box->nextPointerS == NULL) {
            bufferSentence = box;
            pointerSentence->nextPointerS = NULL;
        }
        else {
            box = box->nextPointerS;
            bufferSentence = pointerSentence->nextPointerS;
            box->previousPointer = pointerSentence;
            pointerSentence->nextPointerS = box;
        }
    }
}

void putElementSentenceListPtrUp()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (bufferSentence == NULL) {
        printf("\nBuffer is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else {
        if (pointerSentence->nextPointerS == NULL) {
            bufferSentence->nextPointerS = NULL;
            bufferSentence->previousPointer = pointerSentence;
            pointerSentence->nextPointerS = bufferSentence;
            pointerSentence = bufferSentence;
            bufferSentence = NULL;
            if (pointerSentence->Word != NULL) pointerWord = pointerSentence->Word;
            else pointerWord = NULL;
        }
        else {
            struct elementSentence *box;
            box = pointerSentence->nextPointerS;
            box = pointerSentence->nextPointerS;
            box->previousPointer = bufferSentence;
            bufferSentence->nextPointerS = box;
            bufferSentence->previousPointer = pointerSentence;
            pointerSentence->nextPointerS = bufferSentence;
            pointerSentence = bufferSentence;
            bufferSentence = NULL;
            if (pointerSentence->Word != NULL) pointerWord = pointerSentence->Word;
            else pointerWord = NULL;
        }
        printf("\n   Successful insertion!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void putElementSentenceListPtrDoun()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (bufferSentence == NULL) {
        printf("\nBuffer is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else {
        if (pointerSentence->previousPointer == NULL) {
            bufferSentence->previousPointer = NULL;
            bufferSentence->nextPointerS = pointerSentence;
            pointerSentence->previousPointer = bufferSentence;
            pointer->Sentence = bufferSentence;
            pointerSentence = bufferSentence;
            bufferSentence = NULL;
            if (pointerSentence->Word != NULL) pointerWord = pointerSentence->Word;
            else pointerWord = NULL;
        }
        else {
            struct elementSentence *box;
            box = pointerSentence->previousPointer;
            box->nextPointerS = bufferSentence;
            bufferSentence->previousPointer = box;
            bufferSentence->nextPointerS = pointerSentence;
            pointerSentence->previousPointer = bufferSentence;
            pointerSentence = bufferSentence;
            bufferSentence = NULL;
            if (pointerSentence->Word != NULL) pointerWord = pointerSentence->Word;
            else pointerWord = NULL;
        }
        printf("\n   Successful insertion!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void deleteElementSentenceListBeforePtr()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointerSentence->previousPointer == NULL) {
        printf("        This is the first element of sentence list!\n\n");
        printf("              Push any key to back to menu");
        getch();
    }

    else {
        struct elementSentence *box, *toDelete;
        box = pointerSentence->previousPointer;

        if (box->previousPointer == NULL) {
            free(box);
            pointerSentence->previousPointer = NULL;
            pointer->Sentence = pointerSentence;
            printf("        Element was successfully deleted!\n\n");
            printf("          Push any key to back to menu");
            getch();
        }

        else if (box->previousPointer != NULL) {
            toDelete = pointerSentence->previousPointer;
            box = pointerSentence->previousPointer;
            box = box->previousPointer;
            free(toDelete);
            pointerSentence->previousPointer = box;
            box->nextPointerS = pointerSentence;
            printf("        Element was successfully deleted!\n\n");
            printf("          Push any key to back to menu");
            getch();
        }
    }
}

void deleteElementSentenceListAfterPtr()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointerSentence->nextPointerS == NULL) {
        printf("        This is the last element of sentence list!\n\n");
        printf("              Push any key to back to menu");
        getch();
    }
    else {
        struct elementSentence *box, *toDelete;
        box = pointerSentence->nextPointerS;

        if (box->nextPointerS == NULL) {
            toDelete = box;
            free(toDelete);
            pointerSentence->nextPointerS = NULL;
            printf("        Element was successfully deleted!\n\n");
            printf("          Push any key to back to menu");
            getch();
        }

        else if (box->nextPointerS != NULL) {
            toDelete = pointerSentence->nextPointerS;
            box = pointerSentence->nextPointerS;
            box = box->nextPointerS;
            free(toDelete);
            pointerSentence->nextPointerS = box;
            box->previousPointer = pointerSentence;
            printf("        Element was successfully deleted!\n\n");
            printf("          Push any key to back to menu");
            getch();
        }
    }
}

void addAfterPointerSentence()
{
    short int choice;
    struct elementSentence *ptr, *newSentence, *box;

    if (pointer->Sentence == NULL) {
        newSentence = (struct elementSentence*)malloc(sizeof(struct elementSentence));
        pointer->Sentence = newSentence;
        newSentence->nextPointerS = NULL;
        newSentence->previousPointer = NULL;
        pointerSentence = newSentence;
        pointerSentence->Word = NULL;
        pointerWord = NULL;
    }
    else {
        ptr = pointerSentence;
        if (ptr->nextPointerS == NULL) {
            newSentence = (struct elementSentence*)malloc(sizeof(struct elementSentence));
            newSentence->previousPointer = ptr;
            ptr->nextPointerS = newSentence;
            newSentence->nextPointerS = NULL;
            pointerSentence = newSentence;
            pointerSentence->Word = NULL;
            pointerWord = pointerSentence->Word;
            pointerWord = NULL;
            //pointer->Sentence->Word = NULL;
        }
        else {
            newSentence = (struct elementSentence*)malloc(sizeof(struct elementSentence));
            box = ptr->nextPointerS;
            newSentence->previousPointer = ptr;
            newSentence->nextPointerS = box;
            ptr->nextPointerS = newSentence;
            box->previousPointer = newSentence;
            pointerSentence = newSentence;
            pointerSentence->Word = NULL;
            pointerWord = pointerSentence->Word;
            pointerWord = NULL;
            //pointer->Sentence->Word = NULL;
        }
    }
    printf("\nStart working with list of words (L1)---( 1 )\n");
    printf("Quit------------------------------------( 2 )\n\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    while (choice > 2 || choice < 1) {
        printf("Make your choice again rightly: ");
        scanf("%d", &choice);
    }

    switch (choice){
        case 1: {
            menu3();
            break;
        }
        case 2: {
            break;
        }
    }
}

void beginSentenceListPtr()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointerSentence->previousPointer == NULL) {
        printf("        This is the first element of sentence list!\n\n");
        printf("        Push any key to back to menu");
        getch();
    }
    else {
        while (pointerSentence->previousPointer != NULL) pointerSentence = pointerSentence->previousPointer;
    }
}

void endSentenceListPtr()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointerSentence->nextPointerS == NULL) {
        printf("        This is the last element of sentence list!\n\n");
        printf("        Push any key to back to menu");
        getch();
    }
    else {
        while (pointerSentence->nextPointerS != NULL) pointerSentence = pointerSentence->nextPointerS;
    }
}

void SentenceListPtrUp()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointerSentence->nextPointerS == NULL) {
        printf("        This is the last element of word list!\n\n");
        printf("        Push any key to back to menu");
        getch();
    }
    else pointerSentence = pointerSentence->nextPointerS;
}

void SentenceListPtrDown()
{
    if (pointerSentence == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointerSentence->previousPointer == NULL) {
        printf("        This is the first element of word list!\n\n");
        printf("        Push any key to back to menu");
        getch();
    }
    else pointerSentence = pointerSentence->previousPointer;
}

void addBEforePointerSentence()
{
    short int choice;
    struct elementSentence *ptr, *newSentence, *box;

    if (pointer->Sentence == NULL) {
        newSentence = (struct elementSentence*)malloc(sizeof(struct elementSentence));
        pointer->Sentence = newSentence;
        newSentence->nextPointerS = NULL;
        newSentence->previousPointer = NULL;
        pointerSentence = newSentence;
        pointerSentence->Word = NULL;
        pointerWord = NULL;
    }
    else {
        ptr = pointerSentence;
        if (ptr->previousPointer == NULL) {
            newSentence = (struct elementSentence*)malloc(sizeof(struct elementSentence));
            newSentence->previousPointer = NULL;
            ptr->previousPointer = newSentence;
            newSentence->nextPointerS = ptr;
            pointerSentence = newSentence;
            pointerSentence->Word = NULL;
            //pointerWord = NULL;
            pointer->Sentence = newSentence;
            pointerWord = pointerSentence->Word;
            pointerWord = NULL;
            //pointer->Sentence->Word = NULL;
        }
        else {
            newSentence = (struct elementSentence*)malloc(sizeof(struct elementSentence));
            box = ptr->previousPointer;
            newSentence->previousPointer = box;
            newSentence->nextPointerS = ptr;
            ptr->previousPointer = newSentence;
            box->nextPointerS = newSentence;
            pointerSentence = newSentence;
            pointerSentence->Word = NULL;
            pointerWord = pointerSentence->Word;
            pointerWord = NULL;
            //pointerWord = NULL;
            //pointer->Sentence->Word = NULL;
        }
    }
    printf("\nStart working with list of words (L1)---( 1 )\n");
    printf("Quit------------------------------------( 2 )\n\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    while (choice > 2 || choice < 1) {
        printf("Make your choice again rightly: ");
        scanf("%d", &choice);
    }

    switch (choice){
        case 1: {
            menu3();
            break;
        }
        case 2: {
            break;
        }
    }
}

void addAfterPointerWord()
{
    elementWord *newWord, *box, *ptr;
    char *word;

    ptr = pointerWord;

    if (pointerSentence->Word == NULL) {
        newWord = (struct elementWord*)malloc(sizeof(struct elementWord));
        word = (char*)calloc(10, sizeof(char));
        newWord->word = word;
        printf("Enter the word: ");
        scanf("%s", word);
        newWord->nextPointerW = NULL;
        pointerSentence->Word = newWord;
        pointerWord = pointerSentence->Word;
    }

    else {
        if (pointerWord->nextPointerW != NULL) {
            newWord = (struct elementWord*)malloc(sizeof(struct elementWord));
            word = (char*)calloc(10, sizeof(char));
            newWord->word = word;
            printf("Enter the word: ");
            scanf("%s", word);
            newWord->nextPointerW = pointerWord->nextPointerW;
            pointerWord->nextPointerW = newWord;
            pointerWord = newWord;
        }
        else if (pointerWord->nextPointerW == NULL) {
            //printf("check");
            newWord = (struct elementWord*)malloc(sizeof(struct elementWord));
            word = (char*)calloc(10, sizeof(char));
            newWord->word = word;
            printf("Enter the word: ");
            scanf("%s", word);
            newWord->nextPointerW = NULL;
            pointerWord->nextPointerW = newWord;
            pointerWord = newWord;
        }
    }
}

void makeWordListEmpty()
{
    if (pointer->Sentence->Word == NULL) {
        printf("        The list was already devastated!\n\n");
        printf("          Push any key to back to menu");
        getch();
    }
    else if (pointerSentence->Word->nextPointerW == NULL)
    {
        pointerSentence->Word = NULL;
        printf("        The list was successfully devastated!\n\n");
        printf("            Push any key to back to menu");
        getch();
    }
    else {
        struct elementWord *flag, *toDelete;
        flag = pointerSentence->Word->nextPointerW;
        while (flag->nextPointerW != NULL) {
            toDelete = flag;
            flag = flag->nextPointerW;
            free(toDelete);
        }
        free(flag);
        pointerSentence->Word = NULL;
        printf("        The list was successfully devastated!\n\n");
        printf("            Push any key to back to menu");
        getch();
    }
}

void beginWordsListPtr()
{
    if (pointerWord == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        pointerWord = pointerSentence->Word;
        printf("        The pointer on the beginning of list!\n\n");
        printf("        Push any key to back to menu");
        getch();
    }
}

void WordsListPtrUp()
{
    if (pointerWord == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointerWord->nextPointerW == NULL) {
        printf("        This is the last element of word list!\n\n");
        printf("        Push any key to back to menu");
        getch();
    }
    else pointerWord = pointerWord->nextPointerW;
}

void deleteElementWordsListPtrUp()
{
    if (pointerWord == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointerWord->nextPointerW == NULL) {
        printf("        This is the last element of word list!\n\n");
        printf("            Push any key to back to menu");
        getch();
    }
    else {
        struct elementWord *box, *toDelete;
        toDelete = pointerWord->nextPointerW;
        box = pointerWord->nextPointerW;
        box = box->nextPointerW;
        free(toDelete);
        pointerWord->nextPointerW = box;
        printf("        Element was successfully deleted!\n\n");
        printf("          Push any key to back to menu");
        getch();
    }
}

void takeElementWordsListPtrUp()
{
    if (pointerWord == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (pointerWord->nextPointerW == NULL) {
        printf("\nThis is the last element of list!\n");
        printf("\n  Push any key to back to menu\n");
        getch();
    }
    else {
        struct elementWord *box;
        //bufferWord = (struct elementWord*)malloc(sizeof(struct elementWord));
        box = pointerWord->nextPointerW;
        if (box->nextPointerW == NULL) {
            bufferWord = pointerWord->nextPointerW;
            pointerWord->nextPointerW = NULL;
        }
        else {
            bufferWord = pointerWord->nextPointerW;
            pointerWord->nextPointerW = box->nextPointerW;
        }
    }
}

void putBufferWord()
{
    if (pointerSentence->Word == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else if (bufferWord == NULL) {
        printf("\nBuffer is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
    else {
        if (pointerWord->nextPointerW == NULL) {
            bufferWord->nextPointerW = NULL;
            pointerWord->nextPointerW = bufferWord;
            bufferWord = NULL;
        }
        else {
            bufferWord->nextPointerW = pointerWord->nextPointerW;
            pointerWord->nextPointerW = bufferWord;
            bufferWord = NULL;
        }
        printf("\n   Successful insertion!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void changeElementWordsListPtrUp()
{
    if (pointerWord == NULL) {
        printf("\nThe list is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else if (pointerWord->nextPointerW == NULL) {
        printf("        This is the last element of word list!\n\n");
        printf("            Push any key to back to menu");
        getch();
    }
    else {
        struct elementWord *ptr;
        ptr = pointerWord->nextPointerW;;
        printf("        Enter a replacement word: ");
        scanf("%s", ptr->word);
        printf("\n\n        Word successfully replaced!\n");
        printf("           Push any key to back to menu");
        getch();
    }
}



