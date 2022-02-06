#include <bits/stdc++.h>
using namespace std;

typedef struct _Student
{
    char Id[10];
    char cl[10];
    char name[20];
    double s1;
    double s2;
    double s3;
    double sum;
    struct _Student *next;
} Student;

Student *head=NULL;

void begin();
void input(Student **head, Student **q);
void _delete(Student **head);
void select(Student *head);
void order(Student **head);
void output(Student *head);

void bubble_cl(Student **head);
void bubble_sum(Student **head);

int main()
{
    int p;
    begin();
    Student *q;
    cin >> p;
    while (1)
    {
        if (p == 1)
        {
            input(&head, &q);
        }
        if (p == 2)
        {
            _delete(&head);
        }
        if (p == 3)
        {
            select(head);
        }
        if (p == 4)
        {
            order(&head);
        }
        if (p == 5)
        {
            output(head);
        }
        if (p == 6)
        {
            break;
        }
        cin >> p;
    }
    return 0;
}

void begin()
{
    cout << "1.input" << endl;
    cout << "2.delete" << endl;
    cout << "3.select" << endl;
    cout << "4.order" << endl;
    cout << "5.output" << endl;
    cout << "6.quit" << endl;
    cout << "please input your option" << endl;
}

void input(Student **head, Student **q)
{
    string s;
    while (1)
    {
        Student *temp = (Student *)malloc(sizeof(Student));
        cout << "Id ";
        cin >> temp->Id;
        cout << "class ";
        cin >> temp->cl;
        cout << "name ";
        cin >> temp->name;
        cout << "score1 ";
        cin >> temp->s1;
        cout << "score2 ";
        cin >> temp->s2;
        cout << "score3 ";
        cin >> temp->s3;
        temp->sum = temp->s1 + temp->s2 + temp->s3;
        if (*head == NULL)
        {
            temp = *head;
        }
        else
        {
            (*q)->next = temp;
        }
        (*q) = temp;
        cout << "continue?" << endl;
        cin >> s;
        if (s == "yes")
        {
            continue;
        }
        if (s == "no")
        {
            break;
        }
    }
    begin();
}

void _delete(Student **head)
{
    string s, s2;
    while (1)
    {
        Student *temp = (*head);
        cin >> s2;
        while (temp != NULL)
        {
            if (temp->next->Id == s2 || temp->next->name == s2)
            {
                Student *t = temp->next;
                if (t->next->next == NULL)
                {
                    t->next = NULL;
                    free(t);
                    break;
                }
                else
                {
                    temp->next = temp->next->next;
                    free(temp);
                    break;
                }
            }
            else
            {
                temp = temp->next;
            }
        }
        output(*head);
        cout << "continue?" << endl;
        cin >> s;
        if (s == "yes")
        {
            continue;
        }
        if (s == "no")
        {
            break;
        }
    }
    begin();
}

void select(Student *head)
{
    Student *t = head;
    string s, s2;
    while (t != NULL)
    {
        if (t->Id == s2 || t->cl == s2)
        {
            cout << fixed << setprecision(1) << t->Id << "," << t->cl << "," << t->name << "," << t->s1 << "," << t->s2 << "," << t->s3 << "," << t->sum << endl;
        }
        t = t->next;
    }
    if (t == NULL)
    {
        cout << "there is no eligible student" << endl;
    }
    begin();
}

void order(Student **head)
{
    bubble_cl(head);
    bubble_sum(head);
    output(*head);
    begin();
}

void output(Student *head)
{
    Student *t;
    t = head;
    while (t != NULL)
    {
        cout << fixed << setprecision(1) << t->Id << "," << t->cl << "," << t->name << "," << t->s1 << "," << t->s2 << "," << t->s3 << "," << t->sum << endl;
        t = t->next;
    }
}

void bubble_cl(Student **head)
{
    Student *pb, *pf, temp;
    Student s;
    pf = *head;
    while (pf->next != NULL)
    {
        pb = pf->next;
        while (pb != NULL)
        {
            if (pf->cl > pb->cl)
            {
                temp = *pf;
                *pf = *pb;
                *pb = temp;
                temp.next = pf->next;
                pf->next = pb->next;
                pb->next = temp.next;
            }
            pb = pb->next;
        }
        pf = pf->next;
    }
}

void bubble_sum(Student **head)
{
    Student *pb, *pf, temp;
    Student s;
    pf = *head;
    while (pf->next != NULL)
    {
        pb = pf->next;
        while (pb != NULL)
        {
            if (pf->cl == pb->cl && pf->sum < pb->sum)
            {
                temp = *pf;
                *pf = *pb;
                *pb = temp;
                temp.next = pf->next;
                pf->next = pb->next;
                pb->next = temp.next;
            }
            pb = pb->next;
        }
        pf = pf->next;
    }
}