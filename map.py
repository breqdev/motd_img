with open("img.pbm") as f:
    image = f.read().replace("\n", "")

with open("image.h", "w") as f:
    f.write("uint8_t image[] = {")

    for i in range(0, len(image), 8):
        chars = image[i : i + 8]
        f.write(f"0b{''.join(reversed(chars)).rjust(8, '0')},")

    f.write("};")
