#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int data;
	struct List* next;
} List;

List* createList(List* head) {
	head = (List*)malloc(sizeof(List));
	head->next = NULL;
	return head;
}

List* searchNode(List* head, int data) {
	List* ptr = head;
	while (ptr)
	{
		if (ptr->data == data)
			break;
		ptr = ptr->next;
	}
	return ptr;
}

List* modifyNode(List* head, int data, int position) {
	List* ptr = head;
	while (ptr)
	{
		if (ptr->data == position)
			break;
		ptr = ptr->next;
	}
	if (!ptr) {
		printf("û���ҵ����Ԫ��\n");
		return;
	}
	ptr->data = data;
	return head;
}

void printList(List* head) {
	List* ptr = head->next;
	while (ptr)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

List* insertNode(List* head, int data, int position) {
	List* ptr = head;
	List* ptrFront = NULL;
	List* newNode = (List*)malloc(sizeof(List));
	while (ptr)
	{
		if (ptr->data == position)
			break;
		ptrFront = ptr;
		ptr = ptr->next;
	}
	newNode->data = data;
	ptrFront->next = newNode;
	newNode->next = ptr;
	return head;
}

List* deleteNode(List* head, int position) {
	List* ptr = head;
	List* ptrFront = NULL;
	while (ptr)
	{
		if (ptr->data == position)
			break;
		ptrFront = ptr;
		ptr = ptr->next;
	}
	if (!ptr) {
		system("cls");
		printf("û���ҵ����Ԫ��\n");
		return head;
	}
	ptrFront->next = ptr->next;
	free(ptr);
	return head;
}

int main() {

	List* head = NULL;
	List* temp = NULL;
	head = createList(head);
	int choose = 0;

	int position = 0;
	int data = 0;
	while (1)
	{
		printf("��ѡ����Ҫ���еĲ���\n");
		printf("[1]����Ԫ��\n");
		printf("[2]ɾ��Ԫ��\n");
		printf("[3]�޸�Ԫ��\n");
		printf("[4]��ѯԪ��\n");
		printf("[5]�������\n");
		printf("[0]��       ��\n");
		scanf_s("%d", &choose);
		switch (choose) {
		case 1:
			system("cls");
			printf("��˭��ǰ����루�������Ĳ����ڣ����������룩��");
			scanf_s("%d", &position);
			printf("Ҫ����ʲô��");
			scanf_s("%d", &data);
			head = insertNode(head, data, position);
			break;
		case 2:
			system("cls");
			printf("Ҫɾ��˭��");
			scanf_s("%d", &position);
			head = deleteNode(head, position);
			break;
		case 3:
			system("cls");
			printf("Ҫ�޸�˭��");
			scanf_s("%d", &position);
			printf("Ҫ�޸ĳɣ�");
			scanf_s("%d", &data);
			head = modifyNode(head, data, position);
			break;
		case 4:
			system("cls");
			printf("Ҫ����˭��");
			scanf_s("%d", &data);
			temp = searchNode(head, data);
			printf("�ҵ��˶�Ӧ��Ԫ�أ�%d\n", temp->data);
			break;
		case 5:
			system("cls");
			printList(head);
			break;
		case 0:
			break;
		default:
			system("cls");
			printf("�������\n");
			break;
		}
	}
	return 0;
}