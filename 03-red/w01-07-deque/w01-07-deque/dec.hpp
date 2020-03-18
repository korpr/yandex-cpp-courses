//
//  dec.hpp
//  w01-07-deque
//
//  Created by Sergey Gordeev on 17.03.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef dec_hpp
#define dec_hpp

#include <exception>
#include <vector>

template<typename T>
class Deque {
    public:
        // конструктор по умолчанию;
        Deque():size(0){};
        // константный метод Empty, возвращающий true, если дек не содержит ни одного элемента;
        bool Empty() const{
            return size == 0;
        };
        // константный метод Size, возвращающий количество элементов в деке;
        size_t Size() const{
            return size;
        }
        T& operator[](size_t index){
            return get(index);;
        }
        const  T& operator[](size_t index) const{
            return get(index);;
        }
        // константный и неконстантный метод At(size_t index), генерирующий стандартное исключение out_of_range, если индекс больше или равен количеству элементов в деке;;
        T& At(size_t index) {
            if (index < 0 || index >= size){
                throw std::out_of_range("");
            }
            return get(index);
        }
        const T& At(size_t index) const{
            return At(index);
        }
        //константные и неконстантные версии методов Front и Back, возвращающих ссылки на первый и последний элемент дека соответственно;
        T& Front(){
            return get(0);
        }
        const T& Front() const{
            return Front();
        }
        T& Back(){
            return get(size == 0?0:size -1);
        }
        const T& Back() const{
            return Back();
        }
        //  методы PushFront и PushBack.
        void PushFront(T element){
           push (right ,element);
        }
        void PushBack(T element){
            push (left ,element);
        }
    private:
        size_t size;
        std::vector<T> left;
        std::vector<T> right;
        
        void push(std::vector<T>& v,T& element){
            size++;
            v.push_back(element);
        }
    
    T& get(const size_t& idx){
        if (idx < right.size()){
            return right[right.size() - 1 - idx];
        }
        return left[idx -  right.size()];
    }
};

#endif /* dec_hpp */
