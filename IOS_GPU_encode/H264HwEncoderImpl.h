//
//  H264HwEncoderImpl.h
//  h264v1
//
//  Created by Ganvir, Manish on 3/31/15.
//  Copyright (c) 2015 Ganvir, Manish. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
//#import "YCasterSingleton.h"
//@import AVFoundation;
@protocol H264HwEncoderImplDelegate <NSObject>

- (void)gotSpsPps:(NSData*)sps pps:(NSData*)pps;
- (void)gotEncodedData:(NSData*)data isKeyFrame:(BOOL)isKeyFrame pts:(int)pts dts:(int)dts;

@end
@interface H264HwEncoderImpl : NSObject 

- (void) initWithConfiguration;
- (void) start:(int)width  height:(int)height;
- (void) initEncode:(YCasterSingleton*)ycaserSetingInfo;
- (void) changeResolution:(int)width  height:(int)height;
- (void) encode:(CMSampleBufferRef )sampleBuffer timestamp:(unsigned int)timestamp;
- (void) End;


@property (weak, nonatomic) NSString *error;
@property (weak, nonatomic) id<H264HwEncoderImplDelegate> delegate;

@end
