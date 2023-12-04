import requests
from bs4 import BeautifulSoup

def fetch_tags(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    tags = []

    # Assuming tags are in a table and each row represents a tag
    for row in soup.find_all('tr'):
        cols = row.find_all('td')
        if len(cols) > 3:  # Ensure the row has enough columns
            tag_full = cols[2].text.strip()
            tag_type = cols[3].text.strip()

            # Check if the tag type is one of Short, Long, Rational
            if tag_type in ['Short', 'Long', 'Rational']:
                # Extract the last part of the tag as the key
                tag_key = tag_full.split('.')[-1]
                tags.append((tag_key, tag_full))

    return tags

def generate_cpp_code(tags):
    code = "#include <unordered_map>\n#include <string>\n\n"
    code += "std::unordered_map<std::string, std::string> exifTags = {\n"

    for tag_key, tag_full in tags:
        code_line = f'    {{"{tag_key}", "{tag_full}"}},\n'
        code += code_line

    code += "};\n"
    return code

def main():
    url = "https://exiv2.org/tags.html"
    tags = fetch_tags(url)
    cpp_code = generate_cpp_code(tags)
    print(cpp_code)

if __name__ == "__main__":
    main()