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
app_extensions = [".pdf", ".pdf"]
# get user input
file = input("File name: ").lower().strip()
if any(file.endswith(extension) for extension in img_extensions):
    file_ext = file.split(".")[-1]
    print(f"image/{file}")

elif any(file.endswith(extension) for extension in app_extensions):
    file_ext = file.split(".")[-1]
    print(f"application/{file}")

elif file.endswith(".txt"):
    print("text/plain")
