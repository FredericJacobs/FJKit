//
//  FJCustomLabelStyle.h
//  Storify
//
//  Created by Frederic Jacobs on 2/10/12.
//  Copyright (c) 2012 Frederic Jacobs. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>

extern NSString * const FJCustomLabelStyleDefaultKey;
extern NSString * const FJCustomLabelStyleBoldKey;

@interface FJCustomLabelStyle : NSObject

@property (nonatomic, copy) NSString *fontName;
@property (nonatomic) CGFloat fontSize;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic) CGFloat imageVerticalOffset;

@property (nonatomic, readonly) CTFontRef fontRef;
@property (nonatomic, readonly) CGColorRef colorRef;

+(id)styleWithFont:(UIFont *)font color:(UIColor *)color;
+(id)styleWithImage:(UIImage *)image verticalOffset:(CGFloat)verticalOffset;
+(id)styleWithImage:(UIImage *)image;

@end
