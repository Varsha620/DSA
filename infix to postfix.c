#include<stdio.h>
#include <ctype.h>

int s[20], top = -1;

void push(char ch) {
    top++;
    s[top] = ch;
}

char pop() {
    char x = s[top];
    top--;
    return x;
}

int ps(char ch) {
    if (ch == '^') {
        return 5;
    } else if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

int pi(char ch) {
    if (ch == '^') {
        return 6;
    } else if (ch == '*' || ch == '/') {
        return 4;
    } else if (ch == '+' || ch == '-') {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    int i = 0, k = 0;
    char p[20], v[20], ch, h;
    printf("Enter expression:");
    scanf("%s", &v);
    push('#');
    while (v[i] != '\0') {
        ch = v[i];
        if (ch == '(') {
            push(ch);
        } else if (isalnum(ch)) {
            p[k++] = ch;
        } else if (ch == ')') {
            while (s[top] != '(') {
                p[k++] = pop();
            }
            h = pop();
        } else {
            if (pi(ch) <= ps(ch)) {
                p[k++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while (s[top] != '#') {
        p[k++] = pop();
    }
    p[k++] = '\0';
    printf("%s", p);
    return 0;
}