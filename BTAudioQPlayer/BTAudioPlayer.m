//
//  BTAudioPlayer.m
//  BTAudioQPlayer
//
//  Created by Gary on 13-1-23.
//  Copyright (c) 2013年 Gary. All rights reserved.
//

#import "BTAudioPlayer.h"

@implementation BTAudioPlayer

@end

@implementation BTAudioPlayer(BTAudioPlayerItemControl)

- (void)setActionAtItemEnd:(BTPlayerActionAtItemEnd)actionAtItemEnd {
  NSAssert(actionAtItemEnd == BTPlayerActionAtItemEndLoop, nil);
}

@end