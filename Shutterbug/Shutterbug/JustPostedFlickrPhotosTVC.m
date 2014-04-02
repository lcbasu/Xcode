//
//  JustPostedFlickrPhotosTVC.m
//  Shutterbug
//
//  Created by Lokesh Basu on 02/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "JustPostedFlickrPhotosTVC.h"
#import "FlickrFetcher.h"

@interface JustPostedFlickrPhotosTVC ()

@end

@implementation JustPostedFlickrPhotosTVC

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self fetchPhotos];
}

- (void)fetchPhotos
{
    NSURL *url = [FlickrFetcher URLforRecentGeoreferencedPhotos];
#warning Blocks Main Thread
    NSData *jsonResults = [NSData dataWithContentsOfURL:url];
    NSDictionary *propertyListResults = [NSJSONSerialization JSONObjectWithData:jsonResults
                                                                        options:0
                                                                          error:NULL];
//    NSLog(@"Flickr results = %@", propertyListResults);
    NSArray *photos = [propertyListResults valueForKeyPath:FLICKR_RESULTS_PHOTOS];
    self.photos = photos;
}

@end
