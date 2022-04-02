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
		printf("没有找到这个元素\n");
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
		printf("没有找到这个元素\n");
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
		printf("请选择您要进行的操作\n");
		printf("[1]增加元素\n");
		printf("[2]删除元素\n");
		printf("[3]修改元素\n");
		printf("[4]查询元素\n");
		printf("[5]输出链表\n");
		printf("[0]退       出\n");
		scanf_s("%d", &choose);
		switch (choose) {
		case 1:
			system("cls");
			printf("在谁的前面插入（如果输入的不存在，则在最后插入）：");
			scanf_s("%d", &position);
			printf("要插入什么：");
			scanf_s("%d", &data);
			head = insertNode(head, data, position);
			break;
		case 2:
			system("cls");
			printf("要删除谁：");
			scanf_s("%d", &position);
			head = deleteNode(head, position);
			break;
		case 3:
			system("cls");
			printf("要修改谁：");
			scanf_s("%d", &position);
			printf("要修改成：");
			scanf_s("%d", &data);
			head = modifyNode(head, data, position);
			break;
		case 4:
			system("cls");
			printf("要查找谁：");
			scanf_s("%d", &data);
			temp = searchNode(head, data);
			printf("找到了对应的元素：%d\n", temp->data);
			break;
		case 5:
			system("cls");
			printList(head);
			break;
		case 0:
			break;
		default:
			system("cls");
			printf("输入错误\n");
			break;
		}
	}
	return 0;
}