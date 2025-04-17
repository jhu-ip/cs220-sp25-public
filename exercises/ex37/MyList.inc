// *** DON'T CHANGE THIS FILE ***

template<typename T>
MyList<T>::~MyList() {
  while(head != nullptr) {
    MyNode<T> *next = head->next;
    delete head;
    head = next;
  }
}

template<typename T>
void MyList<T>::insertAtHead(const T& d) {
  head = new MyNode<T>(d, head);
}

template<typename T>
void MyList<T>::insertAtTail(const T& d){
  if(head == nullptr) {
    head = new MyNode<T>(d, nullptr);
  } else {
    MyNode<T>* cur = head;
    while(cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = new MyNode<T>(d, nullptr);
  }
}
