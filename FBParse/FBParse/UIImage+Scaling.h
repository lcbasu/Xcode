//
//  UIImage+Scaling.h
//  FBParse
//
//  Created by Toby Stephens on 02/06/2013.
//  Copyright (c) 2013 Toby Stephens. All rights reserved.
//

@interface UIImage (Scaling)

- (UIImage *) imageScaledToSize:(CGSize)size;
- (UIImage *) imageScaledToFitSize:(CGSize)size;

@end
