//
//  DDiCloudSync.h
//
//  Created by Dominik R. Pich, based on code by Mugunth Kumar (@mugunthkumar) on 1/1/13.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>

@class DDiCloudSync;

@protocol DDiCloudSyncDelegate <NSObject>

@optional
- (NSDictionary*)mergedDefaultsForUpdatingCloud:(NSDictionary*)dictInCloud withLocalDefaults:(NSDictionary*)dict;
- (NSDictionary*)mergedDefaultsForUpdatingLocalDefaults:(NSDictionary*)dict withCloud:(NSDictionary*)dictInCloud;

@end
@interface DDiCloudSync : NSObject
+ (DDiCloudSync*)sharedSync;
- (void)start;
- (void)stop;
- (void)forceUpdateFromiCloud;
- (void)forceUpdateToiCloud;
#if !__has_feature(objc_arc)
@property(assign) id<DDiCloudSyncDelegate> delegate;
#else
@property(weak) id<DDiCloudSyncDelegate> delegate;
#endif
@property(strong) NSDictionary *lastSyncedDict;
@end

//notification sent when local defaults changed due to sync
extern NSString *kDDiCloudDidSyncNotification;