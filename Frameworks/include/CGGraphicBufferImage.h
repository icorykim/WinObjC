//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#pragma once

#include "CGImageInternal.h"

class CGGraphicBufferImage : public __CGImage {
public:
    CGGraphicBufferImage(int width, int height, __CGSurfaceFormat fmt);
    CGGraphicBufferImage(const __CGSurfaceInfo& surfaceInfo);
    CGGraphicBufferImage(const __CGSurfaceInfo& surfaceInfo, const std::shared_ptr<IDisplayTexture>& nativeTexture);
};

class EbrFastTexture;

class CGGraphicBufferImageBacking : public CGImageBacking {
private:
    void* _imageData;
    cairo_surface_t* _surface;
    __CGSurfaceFormat _bitmapFmt;
    CGColorSpaceModel _colorSpaceModel;
    CGBitmapInfo _bitmapInfo;
    DWORD _width, _height;
    DWORD _internalWidth, _internalHeight;
    DWORD _bytesPerRow;
    DWORD _bytesPerPixel;
    DWORD _bitsPerComponent;
    ID2D1RenderTarget* _renderTarget;

public:
    std::shared_ptr<IDisplayTexture> _nativeTexture;

    CGGraphicBufferImageBacking(const __CGSurfaceInfo& surfaceInfo, const std::shared_ptr<IDisplayTexture>& nativeTexture);
    ~CGGraphicBufferImageBacking();

    CGImageRef Copy();

    CGContextImpl* CreateDrawingContext(CGContextRef base);
    void GetPixel(int x, int y, float& r, float& g, float& b, float& a);
    int InternalWidth();
    int InternalHeight();
    int Width();
    int Height();
    int BytesPerRow();
    int BytesPerPixel();
    int BitsPerComponent();
    ID2D1RenderTarget* GetRenderTarget();
    void GetSurfaceInfoWithoutPixelPtr(__CGSurfaceInfo* surfaceInfo);
    __CGSurfaceFormat SurfaceFormat();
    CGColorSpaceModel ColorSpaceModel();
    CGBitmapInfo BitmapInfo();
    void* StaticImageData();
    void* LockImageData();
    void ReleaseImageData();
    cairo_surface_t* LockCairoSurface();
    void ReleaseCairoSurface();
    void SetFreeWhenDone(bool freeWhenDone);
    std::shared_ptr<IDisplayTexture> GetDisplayTexture();
};
