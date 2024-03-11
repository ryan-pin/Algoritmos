#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__


class array_list {
private:
    int* data;
    unsigned int size_, capacity_; 
    void increase_capacity() { //aumenta a capacidade do array
        int* new_data = new int[this->capacity_*2]; //é mais eficiente dobrar a capacidade do array
        for (unsigned int i = 0; i < this->size_; ++i)
            new_data[i] = this->data[i];
        this->capacity_ = this->capacity_*2;
        delete[] this->data;
        this->data = new_data;
    }
public:
    array_list() { //construtor
        data = new int[8];
        this->size_ = 0;
        this->capacity_ = 8;
    }
    ~array_list() { // destrutor
        delete[] data;
    }
    unsigned int size() { // retorna o tamanho
        return this->size_;
    }
    unsigned int capacity() { // retorna a capacidade
        return this->capacity_;
    }
    double percent_occupied() { // retorna quanto % da capacidade foi usado
        return (this->size_ / this->capacity_) * 100;
    }
    bool insert_at(unsigned int index, int value) { // inserir um valor no indice x
        if (index > this->size())
            return false;
        if (this->size() >= this->capacity())
            increase_capacity();
        for (unsigned int i = this->size(); i > index; --i)
            this->data[i] = this->data[i - 1];
        this->data[index] = value;
        this->size_++;
        return true;
    }
    bool remove_at(unsigned int index) { //remove no indice x
        if (index >= this->size_)
            return false; // Não removeu
        for (unsigned int i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { // retorna o valor do indice X
        if (index >= this->size_)
            return -1; //se o indice nao for valido, retorna -1
        return this->data[index];
    }
    void clear() {
        this->size_ = 0;
    }
    void push_back(int value) { //inserir na ultima posição
        if (this->size_ == this->capacity_)
            increase_capacity();
        this->data[size_++] = value;
    }
    void push_front(int value) { //inserir na primeira posição
        this->insert_at(0, value);
    }
    bool pop_back() { //remove na ultima posição
        if(this->size_ == 0){
            return false;
        }
        this->size_--;
        return true;
    }
    bool pop_front() { //remove na primeira posição
        if(this->size_ == 0){
            return false;
        }
        
        for (unsigned int i = 0; i < this->size_ - 1; ++i)
            this->data[i] = this->data[i + 1];
        this->size_--;
        return true;
    }
    int front(){ //retorna o primeiro elemento
        if (this->size_ == 0){
            return -1;
        }
        return this->data[0];
    }
    int back(){ //retorna o ultimo elemento
        if (this->size_ == 0){
            return -1;
        }
        return this->data[size_ -1];
    }
    bool remove(int value) { //remove um elemento pelo valor
        for (unsigned int i = 0; i < this->size_; ++i)
            if (this->data[i] == value){
                for (unsigned int i; i < this->size_ - 1; ++i)
                    this->data[i] = this->data[i + 1];
            this->size_--;
            return true;
        }
        return false;
    }
    int find(int value) { //procura um valor e retorna o indice dele na lista
        for (unsigned int i = 0; i < this->size_; ++i)
            if (this->data[i] == value)
                return i;
        else{ //se nao encontrar retorna -1
            return -1;
        }
    }
    int count(int value) { //conta a quantidade de vezes que um elemento aparece no array
        int qtd =0;
        for (unsigned int i = 0; i < this->size_; ++i)
            if (this->data[i] == value){
                qtd++;
            }
        return qtd;
    }
    int sum() { //retorna a soma de todos os elementos do array
        if (this->size_ == 0){
            return -1;
        }
        int sum = 0;
        for(unsigned int i = 0; i<this->size_; i++){
            sum = sum+this->data[i];
        }
        return sum;
    }
};


#endif // __ARRAY_LIST_IFRN__