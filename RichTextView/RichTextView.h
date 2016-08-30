//
//  RichTextView.h
//
//  Created by 佐毅 on 16/8/30.
//  Copyright © 2016年 上海方创金融信息服务股份有限公司. All rights reserved.
//
#import <UIKit/UIKit.h>

#define SPECIAL_TEXT_NUM   @"specialTextNum"

@class RichTextView;

typedef RichTextView TextView;


@protocol SMKTextViewDelegate <NSObject>

@optional

- (void)textViewEnterDone:(TextView *)textView;

/**
 *  TextView自动改变高度
 *
 *  @param textView
 *  @param size     改变高度后的size
 */
- (void)textView:(TextView *)textView heightChanged:(CGRect)frame;

- (BOOL)textViewShouldBeginEditing:(TextView *)textView;
- (BOOL)textViewShouldEndEditing:(TextView *)textView;

- (void)textViewDidBeginEditing:(TextView *)textView;
- (void)textViewDidEndEditing:(TextView *)textView;

- (BOOL)textView:(TextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)textViewDidChange:(TextView *)textView;

- (void)textViewDidChangeSelection:(TextView *)textView;

- (BOOL)textView:(TextView *)textView shouldInteractWithURL:(NSURL *)URL inRange:(NSRange)characterRange NS_AVAILABLE_IOS(7_0);
- (BOOL)textView:(TextView *)textView shouldInteractWithTextAttachment:(NSTextAttachment *)textAttachment inRange:(NSRange)characterRange NS_AVAILABLE_IOS(7_0);

@end

@interface RichTextView : UITextView

@property (nonatomic, weak) id<SMKTextViewDelegate> myDelegate;
@property (nonatomic, copy, setter=setPlaceHoldString:)   NSString *placeHoldString;
@property (nonatomic, strong, setter=setPlaceHoldTextFont:) UIFont *placeHoldTextFont;
@property (nonatomic, strong, setter=setPlaceHoldTextColor:) UIColor *placeHoldTextColor;


@property (nonatomic, assign, setter=setPlaceHoldContainerInset:) UIEdgeInsets placeHoldContainerInset;


@property (nonatomic, assign, setter=setAutoLayoutHeight:) BOOL autoLayoutHeight;

@property (nonatomic, assign) CGFloat maxHeight;


@property (nonatomic, strong, getter=getSpecialTextColor) UIColor *specialTextColor;

@property (nonatomic, assign) BOOL enableEditInsterText;

- (NSRange)insterSpecialTextAndGetSelectedRange:(NSAttributedString *)specialText
                                  selectedRange:(NSRange)selectedRange
                                           text:(NSAttributedString *)attributedText;

- (void)installStatus;

@end
