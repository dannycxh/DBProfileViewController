//
//  DBProfilePictureView.h
//  DBProfileViewController
//
//  Created by Devon Boyer on 2016-01-08.
//  Copyright (c) 2015 Devon Boyer. All rights reserved.
//
//  Released under an MIT license: http://opensource.org/licenses/MIT
//

#import "DBProfileSelectableView.h"

NS_ASSUME_NONNULL_BEGIN

@class DBProfilePictureView;

/*!
 @abstract The `DBProfilePictureStyle` defines the types of styles for the profile picture.
 */
typedef NS_ENUM(NSInteger, DBProfilePictureStyle) {
    /*!
     @abstract Specifys that no profile picture should be displayed. 
     */
    DBProfilePictureStyleNone,
    /*!
     @abstract Specifys that no profile picture should be cropped to a circle.
     */
    DBProfilePictureStyleRound,
    /*!
     @abstract Specifys that no profile picture should be cropped to a rounded rect.
     */
    DBProfilePictureStyleRoundedRect,
};

@protocol DBProfilePictureViewDelegate <NSObject>

- (void)profilePictureViewDidHighlight:(DBProfilePictureView *)profilePictureView;
- (void)profilePictureViewDidUnhighlight:(DBProfilePictureView *)profilePictureView;

@end

/*!
 @class DBProfilePictureView
 @abstract The `DBProfilePictureView` class displays a profile picture.
 */
@interface DBProfilePictureView : DBProfileSelectableView

@property (nonatomic, weak) id<DBProfilePictureViewDelegate> delegate;

/*!
 @abstract The image view that displays the profile picture.
 */
@property (nonatomic, strong, readonly) UIImageView *imageView;

/*!
 @abstract The image view that overlays the profile picture.
 */
@property (nonatomic, strong, readonly) UIImageView *overlayImageView;

/*!
 @abstract The border width for the profile picture.
 */
@property (nonatomic, assign) CGFloat borderWidth;

/*!
 @abstract The border color for the profile picture.
 */
@property (nonatomic, strong) UIColor *borderColor;

/*!
 @abstract Specifies the style.
 @discussion The default is `DBProfilePictureStyleRoundedRect`.
 */
@property (nonatomic, assign) DBProfilePictureStyle style;

@end

NS_ASSUME_NONNULL_END
