//
//  DBProfileAccessoryViewLayoutAttributes.h
//  Pods
//
//  Created by Devon Boyer on 2016-04-15.
//
//

#import <Foundation/Foundation.h>

@interface DBProfileAccessoryViewLayoutAttributes : NSObject

+ (instancetype)layoutAttributesForAccessoryViewOfKind:(NSString *)accessoryViewKind;

@property (nonatomic, strong, readonly) NSString *representedAccessoryKind;

@property (nonatomic, assign) CGRect frame;

@property (nonatomic, assign) CGRect bounds;

@property (nonatomic, assign) BOOL hidden;

// Constraints - don't touch
@property (nonatomic, strong) NSLayoutConstraint *leadingConstraint;
@property (nonatomic, strong) NSLayoutConstraint *trailingConstraint;
@property (nonatomic, strong) NSLayoutConstraint *leftConstraint;
@property (nonatomic, strong) NSLayoutConstraint *rightConstraint;
@property (nonatomic, strong) NSLayoutConstraint *topConstraint;
@property (nonatomic, strong) NSLayoutConstraint *bottomConstraint;
@property (nonatomic, strong) NSLayoutConstraint *widthConstraint;
@property (nonatomic, strong) NSLayoutConstraint *heightConstraint;
@property (nonatomic, strong) NSLayoutConstraint *centerXConstraint;
@property (nonatomic, strong) NSLayoutConstraint *centerYConstraint;
@property (nonatomic, strong) NSLayoutConstraint *firstBaselineConstraint;
@property (nonatomic, strong) NSLayoutConstraint *lastBaselineConstraint;

@end

typedef NS_ENUM(NSInteger, DBProfileAvatarLayoutSize) {
    DBProfileAvatarLayoutSizeNormal,
    DBProfileAvatarLayoutSizeLarge,
};

typedef NS_ENUM(NSInteger, DBProfileAvatarLayoutAlignment) {
    DBProfileAvatarLayoutAlignmentLeft,
    DBProfileAvatarLayoutAlignmentRight,
    DBProfileAvatarLayoutAlignmentCenter,
};

@interface DBProfileAvatarViewLayoutAttributes : DBProfileAccessoryViewLayoutAttributes

@property (nonatomic, assign) DBProfileAvatarLayoutSize size;

@property (nonatomic, assign) DBProfileAvatarLayoutAlignment alignment;

@property (nonatomic, assign) UIEdgeInsets insets;

@end

typedef NS_ENUM(NSInteger, DBProfileHeaderLayoutStyle) {
    DBProfileHeaderLayoutStyleNone,
    DBProfileHeaderLayoutStyleNavigation,
};

typedef NS_OPTIONS(NSUInteger, DBProfileHeaderLayoutOptions) {
    DBProfileHeaderLayoutOptionNone = (1 << 0),
    DBProfileHeaderLayoutOptionStretch = (1 << 1),
    DBProfileHeaderLayoutOptionExtend = (1 << 2),
};

@interface DBProfileHeaderViewLayoutAttributes : DBProfileAccessoryViewLayoutAttributes

@property (nonatomic, strong, readonly) UINavigationItem *navigationItem;

@property (nonatomic, assign) DBProfileHeaderLayoutStyle style;

@property (nonatomic, assign) DBProfileHeaderLayoutOptions options;

// Constraints - don't touch
@property (nonatomic, strong) NSLayoutConstraint *navigationConstraint;
@property (nonatomic, strong) NSLayoutConstraint *topLayoutGuideConstraint;
@property (nonatomic, strong) NSLayoutConstraint *topSuperviewConstraint;

@end


