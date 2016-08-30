//
//  ViewController.m
//  RichTextView
//
//  Created by 佐毅 on 16/8/30.
//  Copyright © 2016年 上海方创金融信息服务股份有限公司. All rights reserved.
//

#import "ViewController.h"
#import "RichTextView.h"
@interface ViewController ()<SMKTextViewDelegate>
@property (nonatomic, strong)  RichTextView *textView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.textView = [[RichTextView alloc]initWithFrame:CGRectMake(20, 100, 280, 100)];
    [self.view addSubview:self.textView];
    self.textView.layer.cornerRadius = 7.0f;
    self.textView.layer.borderColor = [UIColor purpleColor].CGColor;
    self.textView.layer.borderWidth = 1.0f;
    self.textView.maxHeight = 120;
    self.textView.autoLayoutHeight = YES;
    self.textView.placeHoldString = @"请输入...";
    self.textView.font = [UIFont systemFontOfSize:14];
    self.textView.myDelegate = self;
    self.textView.textColor = [UIColor blueColor];
    self.textView.returnKeyType = UIReturnKeyDone;
    //插入文本的颜色
    self.textView.specialTextColor = [UIColor redColor];
    [self.textView becomeFirstResponder];
    NSMutableAttributedString *str = [[NSMutableAttributedString alloc] initWithString:@"#王健林哈#"];
    [str addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:14] range:NSMakeRange(0, str.length)];
    [self.textView insterSpecialTextAndGetSelectedRange:str selectedRange:self.textView.selectedRange text:self.textView.attributedText];
    
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
