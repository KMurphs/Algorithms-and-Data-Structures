
import re
import sys

def slugify(s): 
  return (re.sub(r'[^A-Za-z0-9]', '-', s)).lower()

if __name__ == "__main__":
  print(slugify(" ".join(sys.argv[1:])))
  # print("Hello World")