"""
media types

image/gif
image/jpg
image/jpeg
image/png
application/pdf
text/plain
application/zip
"""

img_extensions = [".gif", ".jpg", ".jpeg", ".png"]
# get user input
file = input("File name: ").lower().strip()
if any(file.endswith(extension) for extension in img_extensions):
    split
    print(f"image/{file}")