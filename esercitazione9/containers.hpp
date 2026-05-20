#pragma once
#include <queue>
#include <stack>

template<typename T>
class fifo {
private:
	std::queue<T> q;
public:
	fifo() {}
	
	void put(const T& element){
		q.push(element);
	}
	
	T get() {
		T first_element = q.front();
		q.pop();
		return first_element;
	}
	
	bool empty() {
		return (q.empty());
	}
};

template<typename T>
class lifo {
private:
	std::stack<T> s;
public:
	
	lifo() {};
	
	void put(const T& element) {
		s.push(element);
	}
	
	T get() {
		T last_element = s.top();
		s.pop();
		return last_element;
	}
	
	bool empty() {
		return (s.empty());
	}
};
	
	