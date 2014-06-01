//
//  UploadImageViewController.m
//  FBParse
//
//  Created by Toby Stephens on 29/05/2013.
//  Copyright (c) 2013 Toby Stephens. All rights reserved.
//

#import "UploadImageViewController.h"
#import "UIImage+Scaling.h"

@interface UploadImageViewController () <UINavigationControllerDelegate, UIImagePickerControllerDelegate, UITextViewDelegate>
@property (nonatomic, strong) IBOutlet UILabel *lblChooseAnImage;
@property (nonatomic, strong) IBOutlet UIImageView *imgToUpload;
@property (nonatomic, strong) IBOutlet UIButton *btnPhotoAlbum;
@property (nonatomic, strong) IBOutlet UIButton *btnCamera;
@property (nonatomic, strong) IBOutlet UITextField *txtComment;
@property (nonatomic, strong) IBOutlet UIButton *btnUpload;
@property (nonatomic, strong) IBOutlet UIView *vProgressUpload;
@property (nonatomic, strong) IBOutlet UIProgressView *progressUpload;
@end

@implementation UploadImageViewController

- (id) initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {

    }
    return self;
}

- (void) viewDidLoad
{
    [super viewDidLoad];
	
	// Check which types of Image Picker Source are available
	// For example, in the simulator, we won't be able to take a new photo with the camera
	[_btnPhotoAlbum setEnabled:[UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypePhotoLibrary]];
	[_btnCamera setEnabled:[UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]];
}

- (IBAction) chooseImageFromPhotoAlbum
{
	UIImagePickerController *imgPicker = [[UIImagePickerController alloc] init];
    imgPicker.delegate = self;
    imgPicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    [self.navigationController presentModalViewController:imgPicker animated:YES];
}

- (IBAction) createImageWithCamera
{
	UIImagePickerController *imgPicker = [[UIImagePickerController alloc] init];
    imgPicker.delegate = self;
    imgPicker.sourceType = UIImagePickerControllerSourceTypeCamera;
    [self.navigationController presentModalViewController:imgPicker animated:YES];
}

- (IBAction) uploadImage
{
	// Disable the Upload button to prevent multiple touches
	[_btnUpload setEnabled:NO];

	// Check that we have an image selected
	if (!_imgToUpload.image) {
		[[[UIAlertView alloc] initWithTitle:@"Upload Error"
									message:@"Please choose an image before uploading"
								   delegate:self
						  cancelButtonTitle:@"Ok"
						  otherButtonTitles:nil] show];
		[_btnUpload setEnabled:YES];
		return;
	}

	// Check that we have a comment to go with the image
	if (_txtComment.text.length == 0) {
		[[[UIAlertView alloc] initWithTitle:@"Upload Error"
									message:@"Please provide a comment for the image before uploading"
								   delegate:self
						  cancelButtonTitle:@"Ok"
						  otherButtonTitles:nil] show];
		[_btnUpload setEnabled:YES];
		return;
	}
	
	// Show progress
	[_vProgressUpload setHidden:NO];
}

#pragma mark - UIImagePickerControllerDelegate

- (void) imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
	// We've chosen an image, so hide the hint text.
	[_lblChooseAnImage setHidden:YES];

	// Close the image picker
    [picker dismissModalViewControllerAnimated:YES];
	
	// We're going to Scale the Image to fit the image view.
	// This is just to keep traffic size down.
	UIImage *image = (UIImage *)info[UIImagePickerControllerOriginalImage];
	[_imgToUpload setImage:[image imageScaledToFitSize:_imgToUpload.frame.size]];
}


#pragma mark - UITextViewDelegate

// Hide the keyboard when we return from the comment field.
- (BOOL) textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}


@end
