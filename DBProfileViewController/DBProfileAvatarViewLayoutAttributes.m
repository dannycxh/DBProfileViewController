//
//  DBProfileAvatarViewLayoutAttributes.m
//  DBProfileViewController
//
//  Created by Devon Boyer on 2016-04-26.
//  Copyright (c) 2015 Devon Boyer. All rights reserved.
//

#import "DBProfileAvatarViewLayoutAttributes.h"
#import "DBProfileAccessoryViewLayoutAttributes_Private.h"
#import "DBProfileViewController.h"

@implementation DBProfileAvatarViewLayoutAttributes

+ (NSArray<NSString *> *)keyPathsForBindings
{
    return @[NSStringFromSelector(@selector(avatarAlignment)),
             NSStringFromSelector(@selector(edgeInsets))];
}

+ (instancetype)layoutAttributes
{
    return [super layoutAttributesForAccessoryViewOfKind:DBProfileAccessoryKindAvatar];
}

- (instancetype)initWithAccessoryViewKind:(NSString *)accessoryViewKind
{
    self = [super initWithAccessoryViewKind:accessoryViewKind];
    if (self) {
        self.avatarAlignment = DBProfileAvatarAlignmentLeft;
        self.edgeInsets = UIEdgeInsetsMake(0, 0, 72/2.0 - 15, 0);
    }
    return self;
}

#pragma mark - NSObject

- (BOOL)isEqual:(id)object {
    if (![object isKindOfClass:[self class]]) return NO;
    if (![super isEqual:object]) return NO;
    DBProfileAvatarViewLayoutAttributes *otherObject = (DBProfileAvatarViewLayoutAttributes *)object;
    return UIEdgeInsetsEqualToEdgeInsets(self.edgeInsets, otherObject.edgeInsets) && self.avatarAlignment == otherObject.avatarAlignment;
}

#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone
{
    DBProfileAvatarViewLayoutAttributes *copy = [super copyWithZone:zone];
    
    copy.avatarAlignment = self.avatarAlignment;
    copy.edgeInsets = self.edgeInsets;
    
    return copy;
}

@end
