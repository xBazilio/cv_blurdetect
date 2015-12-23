# cv_blurdetect
Small tool for detection if an image is blurry

## require
OpenCV >=2.3.1

## build
```bash
cmake . && make
```

## use
```bash
if `./cv_blurdetect myimage.jpg`; then echo "blurry"; else echo "sharp"; fi
```
