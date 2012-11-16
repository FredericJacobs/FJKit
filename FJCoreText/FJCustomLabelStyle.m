//
//  FJCustomLabelStyle.m
//  Storify
//
//  Created by Frederic Jacobs on 2/10/12.
//  Copyright (c) 2012 Frederic Jacobs. All rights reserved.
//


#import "FJCustomLabelStyle.h"

NSString * const FJCustomLabelStyleDefaultKey = @"fj-default-style";
NSString * const FJCustomLabelStyleBoldKey = @"fj-bold-style";

@implementation FJCustomLabelStyle

@synthesize fontName, fontSize, textColor, image, imageVerticalOffset;
@synthesize fontRef, colorRef;

+(id)styleWithFont:(UIFont *)font color:(UIColor *)color{
	FJCustomLabelStyle *style = [FJCustomLabelStyle new];
	style.fontName = font.fontName;
	style.fontSize = font.pointSize;
	style.textColor = color;
	return style;
}
+(id)styleWithImage:(UIImage *)image verticalOffset:(CGFloat)verticalOffset{
	FJCustomLabelStyle *style = [FJCustomLabelStyle new];
	style.image = image;
	style.imageVerticalOffset = verticalOffset;
	return style;
}
+(id)styleWithImage:(UIImage *)image{
	return [self styleWithImage:image verticalOffset:0];
}

-(void)dealloc{
	[self resetFontRef];
	[self resetTextColor];
}
-(void)resetFontRef{
	if(fontRef){
		CFRelease(fontRef);
		fontRef = nil;
	}	
}
-(void)resetTextColor{
	if(colorRef){
		CFRelease(colorRef);
		colorRef = nil;
	}	
}

-(void)setFontName:(NSString *)_fontName{
	fontName = [_fontName copy];
	[self resetFontRef];
}
-(void)setFontSize:(CGFloat)_fontSize{
	fontSize = _fontSize;
	[self resetFontRef];
}
-(void)setTextColor:(UIColor *)_textColor{
	textColor = _textColor;
}
-(void)setImage:(UIImage *)_image{
	image= _image;
}

-(CTFontRef)fontRef{
	if(!fontRef){
		if(!fontName){
			fontName = @"Helvetica";
		}
		if (fontSize == 0) {
			fontSize = 12;
		}
		fontRef = CTFontCreateWithName((__bridge CFStringRef)fontName, fontSize, NULL);
	}
	return fontRef;
}
-(CGColorRef)colorRef{
	if(textColor){
		return [textColor CGColor];
	}else{
		return [[UIColor blackColor] CGColor];
	}
}


@end
