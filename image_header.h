//////////////////////////////////////////////////////////////////////////
//		struct ImgPackHdr
//
struct ImgPackHdr
{
    // General info
    int32_t ver;			// version (must be 2)
    int16_t hsz;			// size of header structure
    int32_t w;				// width image
    int32_t h;				// hight image
    int32_t format;			// format image
    int64_t tm;				// timestamp
    int32_t mtype;			// type of memory

    // OpenCV storage mode
    int16_t depth;			// depth image
    int16_t channel;		// number of channels
    int32_t stride[3];		// strides

    // Plane YUV storage mode
    int32_t plane_w[3];		// width image (Y/U/V)
    int32_t plane_h[3];		// hight image (Y/U/V)
    int32_t plane_s[3];		// stride width (Y/U/V)
    int32_t plane_offs[3];	// offset buffer
    int32_t plane_bsz[3];	// size of each buffer

    int32_t buf_size;		// size of buffer (next in memory after header, full size memory shared is [hsz + buf_size] )
};