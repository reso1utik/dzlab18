#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_BOOKS 5


struct Novel {
    char title[100];  
    char author[100]; 
    int pages;        
    float rating;     
    int year;         
};


void print_book(const struct Novel* b) {
    printf("«%s» — %s (%d г.), страниц: %d, оценка: %.1f/10\n",
        b->title, b->author, b->year, b->pages, b->rating);
}

int main() {
    setlocale(LC_ALL, "rus");

    struct Novel library[MAX_BOOKS];
    int ch;

    // 1. Организация ввода массива структур
    for (int i = 0; i < MAX_BOOKS; i++) {
        printf("=== Ввод данных о романе №%d ===\n", i + 1);

        printf("Название: ");
        // Используем fgets, чтобы можно было вводить названия с пробелами
        fgets(library[i].title, sizeof(library[i].title), stdin);
       

        printf("Автор: ");
        fgets(library[i].author, sizeof(library[i].author), stdin);
        

        printf("Количество страниц: ");
        scanf("%d", &library[i].pages);

        printf("Средняя оценка (от 0.0 до 10.0): ");
        scanf("%f", &library[i].rating);

        printf("Год издания: ");
        scanf("%d", &library[i].year);

        // Очищаем буфер от остаточного '\n' после scanf перед следующим fgets/getchar
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("\n");
    }

   
    printf("--- Результаты фильтрации (Страниц: 100-200, Оценка > 5) ---\n");
    int found = 0;

    for (int i = 0; i < MAX_BOOKS; i++) {
        // Условие: кол-во страниц от 100 до 200 И оценка больше 5
        if (library[i].pages >= 100 && library[i].pages <= 200 && library[i].rating > 5.0) {
            print_book(&library[i]);
            found++;
        }
    }

    if (found == 0) {
        printf("Романы, соответствующие заданным критериям, не найдены.\n");
    }

    return 0;
}
