'''
a python script to automate generation table of contents with links for md
'''

import re

def extract_headings(file_path):
    headings = []

    with open(file_path, 'r', encoding='utf-8') as file:
        for line in file:
            line = line.strip()
            match = re.match(r'^(#{1,4})\s+(.*)', line)
            if match:
                level = len(match.group(1))
                heading = match.group(2).strip()
                headings.append((level, heading))

    return headings

def generate_toc(headings):
    toc = []
    for level, heading in headings:
        indent = '  ' * (level - 1)
        anchor = re.sub(r'[^a-zA-Z0-9\s]', '', heading).lower().replace(' ', '-')
        toc.append(f'{indent}- [{heading}](#{anchor})')
    return toc

def main():
    file_path = 'chapter1/README.md' 
    headings = extract_headings(file_path)
    toc = generate_toc(headings)
    for line in toc:
        print(line)

if __name__ == '__main__':
    main()
