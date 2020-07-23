#"Grokking Algorithms"
from collections import deque

graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "johny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["johnny"] = []

def person_is_seller(name):
    return name[-1] == 'm'

def search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []
    c = 0
    while search_queue:
        person = search_queue.popleft()
        print person
        if not person in searched:
            c += 1
            if person_is_seller(person):
                print person + " is the seller | " + str(c)
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    return False

search("you")
