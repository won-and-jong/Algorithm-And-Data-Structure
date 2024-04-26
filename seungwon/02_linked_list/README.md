# Linked_list
![](https://www.youtube.com/watch?v=C6MX5u7r72E&list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY&index=5)
1. k번째 원소를 확인/변경하기 위해 O(k)가 필요함
2. 임의의 위치에 원소를 추가/임의 위치의 원소 제거는 0(1)
3. 원소들이 메모리 상에 연속해있지 않아 Cache hit rate가 낮지만 할당이 다소 쉬움

||Array|Linked List|
|:---:|:---:|:---:|
|Search|O(1)|O(n)|
|Insert|O(n)|O(1)|
|Delete|O(n)|O(1)|
|Memory|Static|Dynamic(O(N))|

- 임의의 위치에 있는 원소를 확인/변경 : O(N)
- 임의의 위치에 원소를 추가/삭제 : O(1)

## Types of Linked List
1. Singly Linked List
2. Doubly Linked List (STL list)
3. Circular Linked List
