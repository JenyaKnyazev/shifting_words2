#include <stdio.h>
void right_shift_letter_in_words(char str[]) {
    int index_start_word=0, index_end_word=0,i;
    char ch;
    while (str[index_end_word] != '\0') {
        while (str[index_end_word] == ' ')
            index_end_word++;
        if (str[index_end_word] == '\0')
            return;
        index_start_word = index_end_word;
        while (str[index_end_word] != '\0' && str[index_end_word] != ' ')
            index_end_word++;
        index_end_word--;
        ch = str[index_end_word];
        for (i = index_end_word; i > index_start_word; i--)
            str[i] = str[i - 1];
        str[i] = ch;
        index_end_word++;
    }
}
void left_shift_letter_in_words(char str[]) {
    int index_start_word = 0, index_end_word = 0, i;
    char ch;
    while (str[index_end_word] != '\0') {
        while (str[index_end_word] == ' ')
            index_end_word++;
        if (str[index_end_word] == '\0')
            return;
        index_start_word = index_end_word;
        while (str[index_end_word] != '\0' && str[index_end_word] != ' ')
            index_end_word++;
        index_end_word--;
        ch = str[index_start_word];
        for (i = index_start_word; i < index_end_word; i++)
            str[i] = str[i + 1];
        str[i] = ch;
        index_end_word++;
    }
}
void right_shift_word(char str[]) {
    char word[100];
    int i = 0,r, count_space_after_word=0,count_space_before_word=0,index_word=0;
    while (str[i] != '\0')
        i++;
    i--;
    r = i;
    while (i >= 0 && str[i] == ' ') {
        count_space_after_word++;
        i--;
    }
    while (i >= 0 && str[i] != ' ') {
        word[index_word++] = str[i];
        i--;
    }
    while (i >= 0 && str[i] == ' ') {
        count_space_before_word++;
        i--;
    }
    while (i >= 0) {
        str[r] = str[i];
        i--;
        r--;
    }
    if (count_space_after_word == 0) {
        count_space_after_word = count_space_before_word;
        count_space_before_word = 0;
    }
    while (count_space_after_word  > 0) {
        count_space_after_word--;
        str[r--] = ' ';
    }
    i = 0;
    while (index_word > i) {
        str[r--] = word[i];
        i++;
    }
    while (count_space_before_word > 0) {
        str[r--] = ' ';
        count_space_before_word--;
    }
}
void left_shift_word(char str[]) {
    char word[100];
    int i = 0, r, count_space_after_word = 0, count_space_before_word = 0, index_word = 0;
    while (str[i] == ' ') {
        count_space_before_word++;
        i++;
    }
    while (str[i] != ' ' && str[i] != '\0') {
        word[index_word++] = str[i];
        i++;
    }
    while (str[i] == ' ') {
        count_space_after_word++;
        i++;
    }
    r = 0;
    while (str[i] != '\0') {
        str[r] = str[i];
        r++;
        i++;
    }
    if (count_space_before_word == 0) {
        count_space_before_word = count_space_after_word;
        count_space_after_word = 0;
    }
    while (count_space_before_word > 0) {
        str[r++] = ' ';
        count_space_before_word--;
    }
    i = 0;
    while (i < index_word) {
        str[r++] = word[i];
        i++;
    }
    while (count_space_after_word > 0) {
        str[r++] = ' ';
        count_space_after_word--;
    }
}
void copy(char a[], char b[]) {
    int i=0;
    while (b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
    a[i] = b[i];
}
void main(){
    char str[200];
    char str2[200];
    gets(str);
    copy(str2, str);
    puts("\nright shift letter in words:");
    right_shift_letter_in_words(str2);
    puts(str2);
    copy(str2, str);
    puts("\nleft shift letter in words:");
    left_shift_letter_in_words(str2);
    puts(str2);
    copy(str2, str);
    puts("\nright shift word:");
    right_shift_word(str2);
    puts(str2);
    copy(str2, str);
    puts("\nleft shift word:");
    left_shift_word(str2);
    puts(str2);
    system("pause");
}
