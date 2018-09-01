/*
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2  capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/*
分析：构造一个list来存放最近最少使用的结点，规则如下：链表头是最近最少使用的结点，
		可以用来删除，最后一个节点是最近使用的结点。
	  每次get()时：更新list链表，删除之前的状态，更新为最近使用
	  每次put()时：1.若存在，则更新value，并将list链表状态更新
				   2.若不存在，且容量足够：则直接插入map，更新list链表
				   3.若不存在，容量不够，则删除最近最少使用的结点，即list的头结点，
				     并更新list链表
*/
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
   LRUCache(int capacity):m_capacity(capacity),cur_size(0) {}
    
    int get(int key) {
		unordered_map<int, int>::iterator iter = m_cache.find(key);
		if(iter != m_cache.end())
		{
			update_list(key);
			return iter->second;
		}
		return -1;
    }
    
    void put(int key, int value) {

		//若存在，直接替换
		unordered_map<int, int>::iterator iter = m_cache.find(key);
		if(iter != m_cache.end())
		{
			m_cache[key] = value;
			update_list(key);
			return;
		}
		//若当前容量足够,直接添加
		if(cur_size < m_capacity)
		{
			cur_size++;
			m_cache[key]=value;
			m_list.push_back(key);
			return;
		}
		//若当前容量已满，则删除最少使用的pair
		int tmp_key =m_list.front();
		m_list.pop_front();
		unordered_map<int, int>::iterator iterMap = m_cache.find(tmp_key);
		if(iterMap != m_cache.end())
		{
			m_cache.erase(iterMap);
			m_cache[key] = value;
			m_list.push_back(key);
			return;
		}
    }

private:
	unordered_map<int, int> m_cache;
	int m_capacity;
	int cur_size;
	list<int> m_list;


	//更新m_list链表，使得最近最少使用的放在队列最后
	void update_list(int key)
	{
		for(list<int>::iterator itList = m_list.begin(); itList!=m_list.end(); ++itList)
		{
			if(*itList == key)
			{
				m_list.erase(itList);
				break;
			}
		}
			m_list.push_back(key);
	}
};

/**
 * Your LRUCache object will be instantiated and called as   such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
