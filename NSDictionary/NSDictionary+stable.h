//
//  NSDictionary+stable.h
//  Storify
//
//  Created by Frederic Jacobs on 1/11/12.
//  Copyright (c) 2012 Frederic Jacobs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (stable)
- (id)valueForKeyPath:(NSString *)keyPath;
@end
