#ifndef __MX6S_V4L2_CAPTURE_H__
#define __MX6S_V4L2_CAPTURE_H__

/*****************************************************************
Function:
Description: ����Ƶ
Parameter:
Return: 
		0,successful
		-1,failed
Date:
	[2016/6/20]  wangxw add;
	
**********************************************************************/

int HWE_OpenVideo();

/*****************************************************************
Function:
Description: �ر���Ƶ
Parameter:
Return:
		0,successful
		-1,failed
Date:
	[2016/6/20]  wangxw add;
	
**********************************************************************/

int HWE_CloseVideo();


/*****************************************************************
Function:
Description: ��ȡ��Ƶ����
Parameter:
	[in,out] data,�����洢���ݵĿռ�
	[in]  size,�ռ��С
	[in] enRGBType,��ȡ��Ƶ����Ƶ������Ҫת���ɸ�RGB���ͣ�
		V4L2_PIX_FMT_RGB_CUSTOM ��Ҫת�����ͻ�������Ҫ�Լ�ת����
Return:
Date:
	[2016/6/20]  wangxw add;
	
**********************************************************************/
 
typedef enum V4L2_PIX_FMT_CSC_RGB_TYPE_EN
{
    YUYV_CSC_RGB,
    YUYV_CSC_RGB888,
    UYVY_CSC_RGB565,
    YUV8888_CSC_RGB565,
    V4L2_PIX_FMT_CSC_RGB_CUSTOM,
    V4L2_PIX_FMT_CSC_BUTT
}V4L2_PIX_FMT_CSC_RGB_TYPE_E;


int HWE_GetVideoData(unsigned char *data,int size,V4L2_PIX_FMT_CSC_RGB_TYPE_E enRGBType);




/*****************************************************************
Function:
Description: ��ƵԴͨ��ѡ��
Parameter:
	[in] chn, ��ƵԴͨ��id, С��ADV7180_MAX_INPUT (4)
Return:
Date:
	[2016/7/8]  wangxw add;
	
**********************************************************************/

int HWE_VideoChnSelect(unsigned int chn);

#endif
