//
//  DBProfileCoverPhotoView.h
//  Pods
//
//  Created by Devon Boyer on 2016-01-08.
//
//

#import <UIKit/UIKit.h>

/*!
 @class DBProfileCoverPhotoView
 @abstract The `DBProfileCoverPhotoView` class displays a cover photo and manages an activity indicator.
 */
@interface DBProfileCoverPhotoView : UIView

/*!
 @abstract The image view that displays the cover photo.
 */
@property (nonatomic, strong, readonly) UIImageView *imageView;
@property (nonatomic, strong, readonly) UIView *blurView;
@property (nonatomic, strong, readonly) UIActivityIndicatorView *activityIndicator;

- (void)startRefreshing;
- (void)endRefreshing;

@end