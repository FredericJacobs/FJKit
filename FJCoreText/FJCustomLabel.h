//
//  FJCustomLabel.h
//  Storify
//
//  Created by Frederic Jacobs on 2/10/12.
//  Copyright (c) 2012 Frederic Jacobs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>
#import "FJCustomLabelStyle.h"

// Defining the types of text labels for custom targets and appearance.
// These are the default ones for Twitter-like labels. 

typedef enum{
	kFJTextTypeNone=0,
	kFJTextTypeUsername=1,
	kFJTextTypeLink=2,
    kFJTextTypeHashtag=3
}kFJTextType;

// We are here using a bit-wise mask to define what should be linked (user-interaction enabled)

typedef enum{
	kFJShouldLinkNothing	= 0,
	kFJShouldLinkUsernames	= 1 << 0,
	kFJShouldLinkURLs		= 2 << 0,
    kFJShouldLinkHashtags   = 4 << 0,
}kFJShouldLink;

@class FJCustomLabel;

@protocol FJCustomLabelDelegate <NSObject>
@optional
-(void)customLabelDidBeginTouch:(FJCustomLabel *)customLabel recog:(UILongPressGestureRecognizer *)recog;
-(void)customLabelDidBeginTouchOutsideOfHighlightedText:(FJCustomLabel *)customLabel recog:(UILongPressGestureRecognizer *)recog;
-(void)customLabel:(FJCustomLabel *)customLabel didChange:(UILongPressGestureRecognizer *)recog;
-(void)customLabelDidEndTouch:(FJCustomLabel *)customLabel recog:(UILongPressGestureRecognizer *)recog;
-(void)customLabelDidEndTouchOutsideOfHighlightedText:(FJCustomLabel *)customLabel recog:(UILongPressGestureRecognizer *)recog;
-(void)customLabel:(FJCustomLabel *)customLabel didSelectText:(NSString *)text type:(kFJTextType)textType;
@end


@interface FJCustomLabel : UILabel <UIGestureRecognizerDelegate> {
	CTFramesetterRef framesetter;
	CTFrameRef ctFrame;
	CFMutableAttributedStringRef attrString;
	BOOL shouldTruncate;
	CGColorRef backgroundCGColor;
	UILongPressGestureRecognizer *pressRecog;
	BOOL recogOutOfBounds;
	CGFloat highlightedTextIndex;
	NSString *highlightedText;
	kFJTextType highlightedTextType;
	NSMutableDictionary *styles;
}

@property (nonatomic, readonly) NSString *cleanText;
@property (nonatomic) CTTextAlignment ctTextAlignment;
@property (nonatomic, strong) UIColor *linkColor;
@property (nonatomic, strong) UIColor *activeLinkColor;
@property (nonatomic) CGFloat lineHeight;
@property (nonatomic) int numberOfLines;
@property (nonatomic) BOOL shouldBoldAtNames;
@property (nonatomic) kFJShouldLink shouldLinkTypes;
@property (nonatomic) CGFloat kern;
@property (nonatomic, weak) id<FJCustomLabelDelegate> delegate;

-(BOOL)hasHighlightedText;
+(NSRegularExpression *)usernameRegEx;
+(NSRegularExpression *)hashtagRegEx;

-(void)setDefaultStyle:(FJCustomLabelStyle *)style;
-(void)setStyle:(FJCustomLabelStyle *)style forKey:(NSString *)key;


@end
