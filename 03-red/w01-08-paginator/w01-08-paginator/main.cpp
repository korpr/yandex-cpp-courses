#include "test_runner.h"

#include <numeric>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Ð ÐµÐ°Ð»Ð¸Ð·ÑƒÐ¹Ñ‚Ðµ ÑˆÐ°Ð±Ð»Ð¾Ð½ ÐºÐ»Ð°ÑÑÐ° Paginator

template <typename Iterator>
class Page {
public:
    Page(const Iterator begin, const Iterator end):_begin(begin),_end(end){}
    Iterator begin(){
        return _begin;
    }
    Iterator end(){
        return _end;
    }
    
    const Iterator begin() const{
        return _begin;
    }
    const Iterator end() const{
        return _end;
    }
    size_t size() const{
        return _end - _begin;
    }
private:
   const Iterator _begin;
  const  Iterator _end;
};

template <typename Iterator>
class Paginator {
public:
    Paginator(Iterator begin, Iterator end, size_t page_size){
        size_t size = end - begin;
        size_t full_page_counter =  size / page_size;
        auto page_begin  = begin;
        for (size_t p = 0; p < full_page_counter; ++p){
            auto page_end = page_begin + page_size;
            pages.push_back({page_begin,page_end});
            page_begin = page_end;
        }
        
        if (size % page_size){
            pages.emplace_back(page_begin, end);
        }
    };
    auto begin(){
        return pages.begin();
    };
    auto end(){
        return pages.end();
    };
    
    const auto begin() const{
        return pages.begin();
    };
    const  auto end() const{
        return pages.end();
    };
    size_t size() const
    {
        return pages.size();
    };
private:
    vector<Page<Iterator>> pages;
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    Paginator p(c.begin() ,c.end(), page_size);
    return p;
}

void TestPageCounts() {
    vector<int> v(15);
    
    ASSERT_EQUAL(Paginate(v, 1).size(), v.size());
    ASSERT_EQUAL(Paginate(v, 3).size(), 5u);
    ASSERT_EQUAL(Paginate(v, 5).size(), 3u);
    ASSERT_EQUAL(Paginate(v, 4).size(), 4u);
    ASSERT_EQUAL(Paginate(v, 15).size(), 1u);
    ASSERT_EQUAL(Paginate(v, 150).size(), 1u);
    ASSERT_EQUAL(Paginate(v, 14).size(), 2u);
}

void TestLooping() {
    vector<int> v(15);
    iota(begin(v), end(v), 1);
    
    Paginator<vector<int>::iterator> paginate_v(v.begin(), v.end(), 6);
    ostringstream os;
    for (const auto& page : paginate_v) {
        for (int x : page) {
            os << x << ' ';
        }
        os << '\n';
    }
    
    ASSERT_EQUAL(os.str(), "1 2 3 4 5 6 \n7 8 9 10 11 12 \n13 14 15 \n");
}

void TestModification() {
    vector<string> vs = {"one", "two", "three", "four", "five"};
    for (auto page : Paginate(vs, 2)) {
        for (auto& word : page) {
            word[0] = toupper(word[0]);
        }
    }
    
    const vector<string> expected = {"One", "Two", "Three", "Four", "Five"};
    ASSERT_EQUAL(vs, expected);
}

void TestPageSizes() {
    string letters(26, ' ');
    
    Paginator letters_pagination(letters.begin(), letters.end(), 11);
    vector<size_t> page_sizes;
    for (const auto& page : letters_pagination) {
        page_sizes.push_back(page.size());
    }
    
    const vector<size_t> expected = {11, 11, 4};
    ASSERT_EQUAL(page_sizes, expected);
}

void TestConstContainer() {
    const string letters = "abcdefghijklmnopqrstuvwxyz";
    
    vector<string> pages;
    for (const auto& page : Paginate(letters, 10)) {
        pages.push_back(string(page.begin(), page.end()));
    }
    
    const vector<string> expected = {"abcdefghij", "klmnopqrst", "uvwxyz"};
    ASSERT_EQUAL(pages, expected);
}

void TestPagePagination() {
    vector<int> v(22);
    iota(begin(v), end(v), 1);
    
    vector<vector<int>> lines;
    for (const auto& split_by_9 : Paginate(v, 9)) {
        for (const auto& split_by_4 : Paginate(split_by_9, 4)) {
            lines.push_back({});
            for (int item : split_by_4) {
                lines.back().push_back(item);
            }
        }
    }
    
    const vector<vector<int>> expected = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9},
        {10, 11, 12, 13},
        {14, 15, 16, 17},
        {18},
        {19, 20, 21, 22}
    };
    ASSERT_EQUAL(lines, expected);
}

int main() {
    {
    TestRunner tr;
    RUN_TEST(tr, TestPageCounts);
    RUN_TEST(tr, TestLooping);
    RUN_TEST(tr, TestModification);
    RUN_TEST(tr, TestPageSizes);
    RUN_TEST(tr, TestConstContainer);
    RUN_TEST(tr, TestPagePagination);
    }
}
