#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() { //construtor
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    ~linked_list() { //destrutor
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() { 
        return this->size_; // Retorna a quantidade de elementos da lista.
    }
    unsigned int capacitty() {
        return this->size_; // Retorna a quantidade de elementos da lista, a capacidade é igual ao tamanho
    }
    
    double percent_occupied() { // retorna o quanto de espaço da lista esta sendo usado
        if (this->size_ == 0){
            return 0.0;
        }
        else{
            return 1.0;
        }
    }
    
    bool insert_at(unsigned int index, int value) { // adiciona um elemento na posição X(indice) da lista
        if (index > this->size()){
            return false;            
        }
        int_node* cur = this->head;
        for (unsigned int i=0 ; i<index ; ++index)
            cur = cur->next;
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = cur;
        new_node->prev = cur->prev;
        if (new_node->next != nullptr)
            new_node->next->prev = new_node;
        else 
            this->tail = new_node;
        if (new_node->prev != nullptr)
            new_node->prev->next = new_node;
        else 
            this->head = new_node;
        this->size_ ++;
        
        return true;
        
    }
    
    bool remove_at(unsigned int index) {  // remove um elemento no indice indicado na lista
        if (index >= this->size_)
            return false; // Não removeu
        int_node* to_remove = this->head;
        for (unsigned int i = 0; i < index; ++i)
            to_remove = to_remove->next;
        if (to_remove->prev != nullptr)
            to_remove->prev->next = to_remove->next;
        if (to_remove->next != nullptr)
            to_remove->next->prev = to_remove->prev;
        delete to_remove;
        this->size_ --;

        return true; // Removeu
    }
    
    int get_at(unsigned int index) { // retorna o valor do elemento no indice indicado na lista
        if (index >= this->size()){
            return false;
        }
        int_node* cur = this->head;
        for (unsigned int i = 0; i < index; index++){
            cur = cur->next;
        }
        return cur->value;
    }
    
    void clear() { 
        this->size_ = 0;
    }
    
    void push_back(int value) { // adiciona um elemento no final da lista
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
        this->size_ ++;
    }
    
    void push_front(int value) { // adiciona um elemento na primeira posição da lista
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
        this->size_ ++;
    }
    
    bool pop_back() { // remove o ultimo elemento da lista
        if (this->tail == nullptr)
            return false;
        if (this->head == this->tail) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            this->size_--;
            return true;
        }
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = nullptr;
        this->size_--;
        return true;
    }
    
    bool pop_front() { // remove o primeiro elemento da lista
        if (this->head == nullptr)
            return false;
        if (this->tail == this->head) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            this->size_--;
            return true;
        }
        else {
            this->head = this->head->next;
            delete this->head->prev;
            this->head->prev = nullptr;
            this->size_--;
            return true;
        }
    }
    
    int front() { // retorna o primeiro elemento da lista
        if (this->size() == 0){
            return false;
        }      
        return this->head->value;
    }
    
    int back() { // retorna o ultimo elemento da lista
        if (this->size() == 0){
            return false;
        }               
        return this->tail->value;
    }
    
    bool remove(int value) { //remove a primeira aparição desse valor na lista
        int_node * current = this->head;
        for (unsigned int i = 0; i < size_; ++i)
            if (value == current->value){
                current->prev = current->next;
                current-> next = current->prev;
                size_ = size_ -1;
                return true;
        }
        current = current->next;
        return false;
    }
    
    int find(int value) { //procura um valor e retorna o indice dele na lista
        int_node* current = this->head;
        for (unsigned int i = 0; i < size_; ++i){
            if(current->value == value){
                return i;
            }           
            current = current->next;
        }
    }
    
    int count(int value) { // quantidade de vezes que o valor aparece na lista
        int qtd = 0; 
        int_node * current = this->head;
        for (unsigned int i = 0; i < size_; ++i){
            if (value == current->value){
                qtd++;
            }
        current = current->next;
        }
        return qtd;


    }
    
    int sum() { // soma de todos os elementos da lista
        int sum = 0;
        int_node * current = this->head;
        
        while(current !=0){
            sum = sum + current->value;
            current = current->next;
        }
        return sum;
    }
};

#endif // __LINKED_LIST_IFRN__