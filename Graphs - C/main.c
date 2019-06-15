#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node{
    char name[100];
    int id;
    struct _Node *next;
} Node;

typedef struct _Adj_Row{
    Node *header;
    struct _Adj_Row *next;
} Adj_Row;

typedef struct{
    Adj_Row *header;
} Adj_List;


void swap(Node *a, Node *b)
{
    char name[100];
    int id = a->id;
    strcpy(name, a->name);
    a->id = b->id;
    strcpy(a->name, b->name);
    b->id = id;
    strcpy(b->name, name);
}

void swapAdjRows(Adj_Row *a, Adj_Row *b){
    Node *t1 = a->header;
    a->header = b->header;
    b->header = t1;

}

void sortAdjacencyList(Adj_Row *head)
{
    int flag;
    Adj_Row *temp;
    Adj_Row *last = NULL;

    if (head == NULL){
        return;
    }

    while(flag){
        flag = 0;
        temp = head;

        while (temp->next != last)
        {
            if (temp->header->id > temp->next->header->id)
            {
                swapAdjRows(temp, temp->next);
                flag = 1;
            }
            temp = temp->next;

        }
        last = temp;
    }
}

void sortAdjacentNodes(Node *head)
{
    int flag;
    Node *temp = NULL;
    Node *last = NULL;

    if (head == NULL){
        return;
    }

    while(flag){
        flag = 0;
        temp = head;

        while (temp->next != last)
        {
            if (temp->id > temp->next->id)
            {
                swap(temp, temp->next);
                flag = 1;
            }
            temp = temp->next;
        }
        last = temp;
    }
}



void PrintAdjacencyList(Adj_List *g){
    Adj_Row *p=g->header;
    sortAdjacencyList(p);
    while (p!=NULL){
        Node *p_Node=p->header;
        printf("%s",p_Node->name);
        p_Node=p_Node->next;
        sortAdjacentNodes(p_Node);
        int flag=0;
        while(p_Node!=NULL){
            if (!flag){
                printf(": %s",p_Node->name);
                flag=1;
            }
            else
                printf(" - %s",p_Node->name);
            p_Node=p_Node->next;
        }
        printf("\n");
        p=p->next;
    }

}


void InsertNode(Adj_List *g, int x, char name[]){

    Adj_Row *p=g->header;
    while (p!=NULL){
        Node *p_Node=p->header;
        if(p_Node->id == x){
            printf("Duplicated node.\n");
            return;
        }
        p=p->next;
    }


    Adj_Row *temp = (Adj_Row*) malloc (1 * sizeof(Adj_Row));
    Node *t = (Node*) malloc (1 * sizeof(Node));
    strcpy(t->name, name);
    t->id = x;
    t->next = NULL;
    temp->header = t;
    temp->next = g->header;
    g->header = temp;

}

void DeleteNode(Adj_List *g, int x){
    int flag = 0;
    Adj_Row *p=g->header;
    while (p!=NULL){
        Node *p_Node=p->header;
        if(p_Node->id == x){
            flag = 1;
        }
        p=p->next;
    }
    if(flag){
        Adj_Row *p = g->header;
        Adj_Row *temp = NULL;
        while (p->header->id != x){
            temp = p;
            p = p->next;
        }
        if(temp !=NULL){
            temp->next = p->next;
        }
        else{
            g->header = p->next;
        }

        free(p);

        //deleting nodes for any edges
        Adj_Row *p1=g->header;
        while (p1!=NULL){
            Node *p_node=p1->header;
            Node *t_node=p_node;
            p_node = p_node->next;
            while(p_node!=NULL){
                if(p_node->id == x){
                    t_node->next = p_node->next;
                    free(p_node);
                    break;
                }
                t_node=p_node;
                p_node=p_node->next;
            }
            p1=p1->next;
        }

    }
    else{
        printf("No such node.\n");
    }

}

void DeleteEdge(Adj_List *g, int x, int y){
    int flagx = 0, flagy=0;
    Adj_Row *p=g->header;
    while (p!=NULL){
        Node *p_Node=p->header;
        if(p_Node->id == x){
            flagx = 1;
        }
        if(p_Node->id == y){
            flagy = 1;
        }
        p=p->next;
    }
    if(flagx && flagy){
        Adj_Row *p1=g->header;
        while (p1!=NULL){
            Node *p_node=p1->header;

            if(p_node!=NULL && p_node->id == x){
                Node *t_node=p_node;
                p_node = p_node->next;
                while(p_node!=NULL){
                    if(p_node->id == y){
                        t_node->next = p_node->next;
                        free(p_node);
                        break;
                    }
                    t_node=p_node;
                    p_node=p_node->next;
                }
            }
            p1=p1->next;
        }

    }
    else{
        printf("No such edge.\n");
    }
}

void InsertEdge(Adj_List *g, int x, int y){
    int flagx = 0, flagy=0;
    Adj_Row *p=g->header;
    char xname[100];
    char yname[100];
    while (p!=NULL){
        Node *p_Node=p->header;
        if(p_Node->id == x){
            flagx = 1;
            strcpy(xname, p_Node->name);
        }
        if(p_Node->id == y){
            flagy = 1;
            strcpy(yname, p_Node->name);
        }
        p=p->next;
    }
    if(flagx && flagy){

        Adj_Row *p1=g->header;
        while (p1!=NULL){
            Node *p_node=p1->header;

            if(p_node->id == x){

                Node *t_node=p_node;
                Node *t = (Node*) malloc (1 * sizeof(Node));
                strcpy(t->name, yname);
                t->id = y;
                t->next = t_node->next;
                t_node->next = t;
                //printf("%s",p_node->next->name);
                //printf("%s",p_node->name);
            }
            //else if(p_node->id == y){
              //  Node *t_node=p_node;
                //p_node = p_node->next;
                //Node *t = (Node*) malloc (1 * sizeof(Node));
                //strcpy(t->name, xname);
                //t->id = x;
                //t->next = t_node;
                //t_node = t;
            //}
            p1=p1->next;
        }
    }
    else{
        printf("No such node.\n");
    }
}

int main(){
    char command[100];
    Adj_List g;
    g.header=NULL;

    while (scanf("%s", command)){
        if (strcmp(command, "InsertNode")==0){
            int x;
            char name[100];
            scanf("%d %s", &x, name);
            InsertNode(&g, x, name);
        }
        else if (strcmp(command, "InsertEdge")==0){
            int x, y;
            scanf("%d %d", &x, &y);
            InsertEdge(&g, x, y);
        }
        else if (strcmp(command, "DeleteNode")==0){
            int x;
            scanf("%d",&x);
            DeleteNode(&g, x);
        }
        else if (strcmp(command, "DeleteEdge")==0){
            int x,y;
            scanf("%d %d",&x, &y);
            DeleteEdge(&g, x, y);
        }
        else if (strcmp(command, "PrintAdjacencyList")==0){
            PrintAdjacencyList(&g);
        }
        else if (strcmp(command, "Exit")==0){
            return 0;
        }
        else
            printf("No such command\n");
    }
    return 0;
}


