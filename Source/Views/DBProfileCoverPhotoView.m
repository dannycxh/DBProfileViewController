//
//  DBProfileCoverPhotoView.m
//  DBProfileViewController
//
//  Created by Devon Boyer on 2016-01-08.
//  Copyright (c) 2015 Devon Boyer. All rights reserved.
//
//  Released under an MIT license: http://opensource.org/licenses/MIT
//

#import "DBProfileCoverPhotoView.h"
#import "DBProfileTintView.h"

UIImage *DBProfileImageByCroppingImageToSize(UIImage *image, CGSize size) {
    
    CGFloat oldWidth = image.size.width;
    CGFloat oldHeight = image.size.height;
    
    CGFloat scaleFactor = (oldWidth > oldHeight) ? size.width / oldWidth : size.height / oldHeight;
    
    CGFloat newHeight = oldHeight * scaleFactor;
    CGFloat newWidth = oldWidth * scaleFactor;
    CGSize newSize = CGSizeMake(newWidth, newHeight);
    
    if ([[UIScreen mainScreen] respondsToSelector:@selector(scale)]) {
        UIGraphicsBeginImageContextWithOptions(newSize, NO, [[UIScreen mainScreen] scale]);
    } else {
        UIGraphicsBeginImageContext(newSize);
    }
    
    [image drawInRect:CGRectMake(0, 0, newSize.width, newSize.height)];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return newImage;
}

@interface DBProfileCoverPhotoView () {
    UIImage *_originalImage;
}

@property (nonatomic, strong) DBProfileTintView *tintView;

@end

@implementation DBProfileCoverPhotoView

- (instancetype)init {
    self = [super init];
    if (self) {
        self.backgroundColor = [UIColor whiteColor];
        self.userInteractionEnabled = YES;
        self.clipsToBounds = YES;
        _shouldCropImageBeforeBlurring = YES;
        
        _tintView = [[DBProfileTintView alloc] init];
        _tintView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        _tintView.frame = self.frame;
        [self addSubview:_tintView];
    }
    return self;
}

- (void)setShouldApplyTint:(BOOL)shouldApplyTint {
    _shouldApplyTint = shouldApplyTint;
    self.tintView.hidden = !shouldApplyTint;
}

- (void)setShouldCropImageBeforeBlurring:(BOOL)shouldCropImageBeforeBlurring
{
    _shouldCropImageBeforeBlurring = shouldCropImageBeforeBlurring;
    [self setCoverPhotoImage:_originalImage animated:NO];
}

- (void)setCoverPhotoImage:(UIImage *)image animated:(BOOL)animated
{
    if (!image) return;
    _originalImage = image;
    
    if (!image) return;
    self.initialImage = (self.shouldCropImageBeforeBlurring) ? DBProfileImageByCroppingImageToSize(image, self.frame.size) : image;
    
    if (animated) {
        self.imageView.alpha = 0;
        [UIView animateWithDuration: 0.3 animations:^{
            self.imageView.alpha = 1;
        }];
    }
}

- (void)applyLayoutAttributes:(DBProfileHeaderViewLayoutAttributes *)layoutAttributes
{
    [super applyLayoutAttributes:layoutAttributes];
    
    if (layoutAttributes.style == DBProfileHeaderLayoutStyleNone) {
        self.shouldApplyTint = NO;
        self.blurEnabled = NO;
    }
}

@end
