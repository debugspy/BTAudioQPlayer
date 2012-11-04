//
//  BTPlayerItem.h
//  BTAudioQPlayer
//
//  Created by He baochen on 12-10-31.
//  Copyright (c) 2012年 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BTPlayerItem: NSObject {
  NSMutableData *                 _cacheData;
  volatile NSUInteger                      _byteWriteIndex;
//  NSUInteger                      _packetBufferSize;
//  NSUInteger                      _expectedContentLength;
//  
//  AudioStreamBasicDescription _asbd;
  
//  NSUInteger  _processedPacketsSizeTotal;
//  NSUInteger  _processedPacketsCount;

//  NSInteger     _seekByteOffset;
//  Float64       _seekTime;
  Float64       _packetDuration;
  Float64       _sampleRate;
  BOOL          _isFormatVBR;
//  BOOL          _discontinuity;
  volatile BOOL _isDataComplete;
}
@property (nonatomic, retain) NSURL *url;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *fileFormat;
@property (nonatomic) AudioStreamBasicDescription asbd;
@property (nonatomic) NSUInteger  byteWriteIndex;
@property (nonatomic) NSUInteger  packetBufferSize;
@property (nonatomic) NSUInteger  expectedContentLength;
@property (nonatomic) NSUInteger  processedPacketsSizeTotal;
@property (nonatomic) NSUInteger  processedPacketsCount;
@property (nonatomic) NSUInteger  dataOffset;
@property (nonatomic) NSUInteger  bitRate;

@property (nonatomic) volatile NSUInteger  seekByteOffset;
@property (nonatomic) Float64     seekTime;
@property (nonatomic, readonly) Float64     packetDuration;
@property (nonatomic, readonly) Float64     sampleRate;
@property (nonatomic, readonly) BOOL        isFormatVBR;
@property (nonatomic) BOOL        discontinuity;
@property (readonly)   NSMutableData *cacheData;
@property (nonatomic, readonly)   BOOL isDataComplete;
@property (nonatomic)   BOOL seekRequested;
+ (BTPlayerItem *)playerItemWithURL:(NSURL *)URL;
- (id)initWithURL:(NSURL*)URL;
- (void)appendData:(NSData*)data;
- (NSUInteger)availableDataLength;
//- (BOOL)hasMoreData;
//- (BOOL)isEnd;
- (Float64)duration;
- (Float64)calculatedBitRate;
- (void)reset;
@end
