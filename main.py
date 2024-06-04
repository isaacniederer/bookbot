def main():
    with open("books/frankenstein.txt") as f:
        file_contains = f.read()
        word_count(file_contains.split())

def sort_on(dict):
    return dict["num"]

def word_count(words):
    list = []
    dict = {}
    for word in words:
        word = word.lower()
        for i in range(0, len(word)):
            char = word[i]
            if char in dict:
                dict[char] += 1
            elif char.isalpha():
                dict[char] = 1
    
    for key in dict:
        new_dict = {}
        count = 0
        new_dict["key"] = key
        new_dict["num"] = dict[key]
        list.append(new_dict)

    list.sort(reverse=True, key=sort_on)

    print("--- Begin report of books/frankenstein.txt ---")
    print(f"{len(words)} words found in the document")
    print("")
    
    for item in list:
        key = item["key"]
        num = item["num"]
        print(f"The '{key}' character was found {num} times")

    print("--- End Report ---")

main()
